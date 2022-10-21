#include "Terminal.h"
#include <stdio.h>
#include<string.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	printf("Enter The Transaction Date (DD/MM/YYYY): \n");
	gets(termData->transactionDate);

	if (strlen(termData->transactionDate) == 0 || strlen(termData->transactionDate) != 10 || termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/') {
		return WRONG_DATE;
	}
	else {
		return OK;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	if (cardData->cardExpirationDate[3] < termData->transactionDate[8]) {
		return EXPIRED_CARD;
	}
	else if (cardData->cardExpirationDate[3] > termData->transactionDate[8]) {
		return OK;
	}
	else
	{
		if (cardData->cardExpirationDate[4] < termData->transactionDate[9]) {
			return EXPIRED_CARD;
		}

		else if (cardData->cardExpirationDate[4] > termData->transactionDate[9]) {
			return OK;
		}
		else
		{
			if (cardData->cardExpirationDate[0] < termData->transactionDate[3]) {
				return EXPIRED_CARD;
			}
			else if (cardData->cardExpirationDate[0] > termData->transactionDate[3]) {
				return OK;
			}
			else
			{
				if (cardData->cardExpirationDate[1] <= termData->transactionDate[4]) {
					return EXPIRED_CARD;
				}
				else if (cardData->cardExpirationDate[1] > termData->transactionDate[4]) {
					return OK;
				}
			}

		}
	}
}
	
	



EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData){
	
	printf("Enter Transaction Amount:\n");
	scanf_s("%f", &termData->transAmount);
	getchar();
	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT;
	}
	else return OK;

}


EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	termData->maxTransAmount = 30000;
	if (termData->maxTransAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return OK;
	}

}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {

	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	else { 
		return OK; }

}