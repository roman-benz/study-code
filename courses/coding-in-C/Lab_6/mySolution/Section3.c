#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD_SENSOR1 0.8
#define THRESHOLD_SENSOR2 0.7
#define SAMPLES 3000
#define LINESIZE 15

typedef struct {
    float time;
    double probability;
} SensorData;

typedef struct {
    int id;
    double threshold;
    SensorData *data;   
    int n;              
} Sensor;

int read_sensor(FILE *f, Sensor *s, SensorData *buffer, int max_samples);
void print_intervals(const Sensor *sensor, const char *name);

int main(void)
{
    Sensor sensor1 = { .id = 1, .threshold = THRESHOLD_SENSOR1, .data = NULL, .n = 0 };
    Sensor sensor2 = { .id = 2, .threshold = THRESHOLD_SENSOR2, .data = NULL, .n = 0 };

    FILE *f1 = fopen("../sensor1.txt", "r");
    FILE *f2 = fopen("../sensor2.txt", "r");

    if (!f1 || !f2) {
        printf("Eine Textdatei konnte nicht geoeffnet werden\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 1;
    }

    SensorData data1[SAMPLES];
    SensorData data2[SAMPLES];

    sensor1.data = data1;
    sensor2.data = data2;

    sensor1.n = read_sensor(f1, &sensor1, data1, SAMPLES);
    sensor2.n = read_sensor(f2, &sensor2, data2, SAMPLES);

    fclose(f1);
    fclose(f2);

    float overlapped[SAMPLES] = {0};
    for (int i = 0; i < sensor1.n && i < sensor2.n; i++)
    {
        int det1 = (data1[i].probability > sensor1.threshold);
        int det2 = (data2[i].probability > sensor2.threshold);

        if (det1 && det2)
        {
            overlapped[i] = 1.0f;
        }
        else
        {
            overlapped[i] = 0.0f;
        }
    }
    print_intervals_from_signal(signal1, times, n, "Sensor1");
    print_intervals_from_signal(signal2, times, n, "Sensor2");
    print_intervals_from_signal(overlap, times, n, "Fusion");
    

    return 0;
}

int read_sensor(FILE *f, Sensor *s, SensorData *buffer, int max_samples)
{
    (void)s; 
    char line[LINESIZE];
    int count = 0;

    while (count < max_samples && fgets(line, sizeof line, f) != NULL)
    {
        float time;
        double prob;

        if (sscanf(line, "%f %lf", &time, &prob) == 2)
        {
            buffer[count].time = time;         
            buffer[count].probability = prob;
            count++;
        }
    
    }

    return count;
}

void print_intervals(const Sensor *sensor, const char *name)
{
    printf("\n%s:\n", name);

    int in_interval = 0;
    float starttime = 0.0f;
    int intervals = 0;

    for (int i = 0; i < sensor->n; i++)
    {
        int flag = (sensor->data[i].probability > sensor->threshold);

        if (!in_interval && flag) {
            starttime = sensor->data[i].time;
            printf("Start: %.3f ", starttime);
            in_interval = 1;
        }
        else if (in_interval && !flag) {
            float endtime = sensor->data[i - 1].time;
            printf("Ende: %.3f\n", endtime);
            in_interval = 0;
            intervals++;
        }
    }

    if (in_interval) {
        float endtime = sensor->data[sensor->n - 1].time;
        printf("Ende: %.3f\n", endtime);
        intervals++;
    }

    if (intervals == 0) {
        printf("(keine Detektionen)\n");
    }
}