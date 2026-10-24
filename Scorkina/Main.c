
#include <stdio.h>

#define N 12

int main() {
    int snr[N] = {
        -42, -38, -25, -17, -33, -45,
        -29, -12, -36, -41, -22, 30
    };

    int minSNR = snr[0];
    int maxSNR = snr[0];
    int minClient = 0;
    int maxClient = 0;
    int sum = 0;

    int excellent = 0;
    int good = 0;
    int bad = 0;

    for (int i = 0; i < N; i++) {
        sum += snr[i];

        if (snr[i] < minSNR) {
            minSNR = snr[i];
            minClient = i;
        }

        if (snr[i] > maxSNR) {
            maxSNR = snr[i];
            maxClient = i;
        }

        if (snr[i] >= 35)
            excellent++;

        if (snr[i] >= 20)
            good++;

        if (snr[i] < 20)
            bad++;
    }

    double average = (double)sum / N;
    int spread = maxSNR - minSNR;

    printf("===== Otchet po Wi-Fi (N=%d) =====\n\n", N);

    printf("Minimalny SNR : %d dB (klient %02d)\n",
           minSNR, minClient + 1);

    printf("Maksimalny SNR: %d dB (klient %02d)\n",
           maxSNR, maxClient + 1);

    printf("\nSredniy SNR: %.2f dB\n", average);

    printf("\n----------------------------------\n\n");

    printf("Klientov s SNR >= 35 dB: %d\n", excellent);
    printf("Klientov s SNR >= 20 dB: %d\n", good);
    printf("Klientov s SNR < 20 dB : %d\n", bad);

    printf("\n----------------------------------\n\n");

    printf("Razbros (max-min): %d dB\n", spread);

    if (bad == 0) {
        printf("Otsenka: otlichnaya\n");
    } else if (bad <= 3) {
        printf("Otsenka: rabochaya, no est problemnye klienty\n");
    } else {
        printf("Otsenka: plohoe pokrytie\n");
    }

    return 0;
}
