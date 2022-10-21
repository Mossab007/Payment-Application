#include<stdio.h>
#include "App.h"
void appStart(void) {

	while (1) {
		int test;
		test = getCardHolderName(&card_Data);
		if (test == WRONG_NAME) {
			printf("WRONG_NAME! \n");
		}
		else {
			test = getCardExpiryDate(&card_Data);
			if (test == WRONG_EXP_DATE)
			{
				printf("WRONG_EXP_DATE! \n");
			}
			else {
				test = getCardPAN(&card_Data);
			if (test == WRONG_PAN) {
				printf(" WRONG_PAN! \n");
			}
			else {
				test = getTransactionDate(&terminal_Data);
				if (test == WRONG_DATE) {
				printf("WRONG_DATE! \n");
			}
			else {
				test = isCardExpired(&card_Data, &terminal_Data);
			if (test == EXPIRED_CARD) {
				printf("EXPIRED_CARD! \n");
			}
			else {

				test = getTransactionAmount(&terminal_Data);
			if (test == INVALID_AMOUNT) {
				printf("INVALID_AMOUNT! \n");
			}
			else {
				test = setMaxAmount(&terminal_Data);
				
			if (test == INVALID_MAX_AMOUNT) {
				printf("INVALID_MAX_AMOUNT! \n");
			}
			else {

				test = isBelowMaxAmount(&terminal_Data);
			if (test == EXCEED_MAX_AMOUNT) {
				printf("EXCEED_MAX_AMOUNT! \n");
			}
			else {
				test = recieveTransactionData(&transaction_Data);
				if (test == DECLINED_STOLEN_CARD) {
					printf("DECLINED_STOLEN_CARD! \n");
				}
				else if (test == DECLINED_INSUFFECIENT_FUND) {
					printf("DECLINED_INSUFFECIENT_FUND! \n");
				}
				else if (test == APPROVED) {
					continue;
				}
			}
			saveTransaction(&transaction_Data);
			
									}
								}
							}
						}
					}
				}
			}
}}
