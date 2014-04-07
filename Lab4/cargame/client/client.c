#include "client.h"

int running;

#define clamp(n, l, h) (n < l ? l : n) > h ? h : (n < l ? l : n)

void usage()
{
	fprintf(stderr, "Usage: client HOST PORT\n");
	exit(1);
}

void err(char* msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void killsig(int s)
{
	running = 0;
}

void setupsig()
{
	struct sigaction sighandle;

	sighandle.sa_handler = killsig;
	sigemptyset(&sighandle.sa_mask);
	sighandle.sa_flags = 0;

	sigaction(SIGINT, &sighandle, NULL);
}

int main(int argc, char** argv)
{
	int byteorder = 1;
	int statuslen;
	char status[100];
	int oldlaps;
	InputPacket inpack;
	OutputPacket outpack;
	int sock, port;
	struct sockaddr_in addr;
	struct hostent *host;

	if (argc != 3) usage();

	setupsig();

	host = gethostbyname(argv[1]);
	if (host == NULL) err("Failed to find host\n");
	port = atoi(argv[2]);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) err("Failed to open socket");

	bzero((char *) &addr, sizeof(addr));
	addr.sin_family = AF_INET;
	bcopy((char *)host->h_addr, (char *)&addr.sin_addr.s_addr, host->h_length);
	addr.sin_port = htons(port);
	if (connect(sock,(struct sockaddr *) &addr,sizeof(addr)) < 0)
		err("Failed to connect");

	running = 1;

	// It's easier to just get the Java end to do the conversion...
	send(sock, &byteorder, 4, 0);

	recv(sock, &statuslen, 4, MSG_WAITALL);
	if (statuslen >= 0)
	{
		recv(sock, &status, statuslen, MSG_WAITALL);
		status[statuslen] = 0;
		running = 0;
		printf("Error: %s\n", status);
	}

	// Control loop:
	while (running)
	{
		oldlaps = inpack.laps;
		recv(sock, &inpack.accelaration, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.steering, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.speed, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.laps, sizeof(int), MSG_WAITALL);
		recv(sock, &inpack.sen_mid_dist, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.sen_close_left_dist, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.sen_close_right_dist, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.sen_left_dist, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.sen_right_dist, sizeof(double), MSG_WAITALL);
		recv(sock, &inpack.sen_mid_type, sizeof(SensorType), MSG_WAITALL);
		recv(sock, &inpack.sen_close_left_type, sizeof(SensorType), MSG_WAITALL);
		recv(sock, &inpack.sen_close_right_type, sizeof(SensorType), MSG_WAITALL);
		recv(sock, &inpack.sen_left_type, sizeof(SensorType), MSG_WAITALL);
		recv(sock, &inpack.sen_right_type, sizeof(SensorType), MSG_WAITALL);

		if (oldlaps != inpack.laps & running) printf("Lap count: %d\n", inpack.laps);

		outpack.accelaration = inpack.accelaration;
		outpack.steering = inpack.steering;
		control(&inpack, &outpack);
		outpack.tintr = clamp(outpack.tintr, 0, 255);
		outpack.tintg = clamp(outpack.tintg, 0, 255);
		outpack.tintb = clamp(outpack.tintb, 0, 255);
		send(sock, &outpack.accelaration, sizeof(double), 0);
		send(sock, &outpack.steering, sizeof(double), 0);
		send(sock, &outpack.tintr, sizeof(int), 0);
		send(sock, &outpack.tintg, sizeof(int), 0);
		send(sock, &outpack.tintb, sizeof(int), 0);
		// Extra running int:
		send(sock, &running, sizeof(int), 0);
	}
	send(sock, &running, sizeof(int), 0);
	printf("finishing...\n");

	shutdown(sock, 0);
	close(sock);

	return 0;
}
