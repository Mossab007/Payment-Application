#include"Card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("Enter Card Holder Name:\n");
	gets(cardData->cardHolderName);

	if (strlen(cardData->cardHolderName) >= 20 && strlen(cardData->cardHolderName) <= 24) {
		return OK;
	}
	else
	{
		return WRONG_NAME;
	}
}
EN_cardError_t getCardExpiryDate( ST_cardData_t* cardData) {
	printf("Enter Expiry Date:\n");
	gets(cardData->cardExpirationDate);
	if (strlen(cardData->cardExpirationDate) == 5 && cardData->cardExpirationDate[2] ==  '/' ) {
		return OK;
	}
	else
	{
		return WRONG_EXP_DATE;


	}

}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("Enter Card PAN:\n");
	gets(cardData->primaryAccountNumber);
	if (strlen(cardData->primaryAccountNumber) >= 16 && strlen(cardData->primaryAccountNumber) <= 19) {
		return OK;
	}
	else
	{
		return WRONG_PAN;

	}


}
