#include<stdio.h>
#include<stdlib.h>

#define ISSUES 5
#define RATINGS 10

void recordresponse(int issue, int rating);
void highestratings();
void lowestratings();
float averagerating(int issue);
void displayresults();

int responses[ISSUES][RATINGS];
const char *topics[ISSUES] = { "Global Warming", "The Economy", "War", "Health Care", "Education" };

int main() {
	int response, i;
	do
	{
		printf("Please rate the folloeing topics on a scale from 1 - 10"
			"\n 1 = least important, 10 = most important\n");

		for (i = 0; i < ISSUES; i++) {

			do {
				printf("%s? ", topics[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again.");
		scanf_s("%d", &response);

	} while (response != 1);

	displayresults();
	system("pause");
	return 0;
}

void recordresponse(int issue, int rating)
{
	responses[issue][rating - 1]++;
}

void highestratings()
{
	int highrating = 0;
	int hightopic = 0;
	int i, j;

	for (i = 0; i < ISSUES; i++) {
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++) {
			topicrating += responses[i][j] * (j + 1);
		}
		if (highrating < topicrating) {
			highrating = topicrating;
			hightopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[hightopic]);
	printf("with a total rating of %d\n", highrating);
}

void lowestratings() {
	int lowrating = 0;
	int lowtopic = 0;
	int i, j;

	for (i = 0; i < ISSUES; i++) {
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++) {
			topicrating += responses[i][j] * (j + 1);
		}
		if (i == 0) {
			lowrating = topicrating;
		}
		if (lowrating > topicrating) {
			lowrating = topicrating;
			lowrating = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowtopic]);
	printf("with a total rating of %d\n", lowrating);
}

float averagerating(int issue) {
	float total = 0;
	int counter = 0;
	int i;

	for (i = 0; i < RATINGS; i++) {
		if (responses[issue][i] != 0) {
			total += responses[issue][i] * (i + 1);
			counter += responses[issue][i];
		}
	}
	return total / counter;
}

void displayresults() {
	int i, j;
	printf("%20s", "Topic");

	for (i = 1; i <= RATINGS; i++) {
		printf("%4d", i);
	}
	printf("%20s", "Average Rating");

	for (i = 0; i < ISSUES; i++) {
		printf("%20s", topics[i]);
		for (j = 0; j < RATINGS; j++) {
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", averagerating(i));
	}
	highestratings();
	lowestratings();
	
}
