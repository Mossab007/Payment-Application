#include "Server.h"
#include <string.h>


ST_accountsDB_t Database[255] = {
									{4000,"0104444444444444444"},
									{3000,"0103333333333333333"},
									{2000,"0102222222222222222"},
									{1000,"0101111111111111111"},
									{3000,"0100000000000000000"},
									{2000,"222222222222222222"},
									{1000,"1111111111111111"}
};

int NUM_account;
ST_transaction_t entryData[255] = { 0 };
uint32_t seq_num=1;

EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	int x=0;
	for (int i = 0; i < 7; i++) {
	x=	strcmp(cardData->primaryAccountNumber, Database[i].primaryAccountNumber);
	if (x == 0) {
		NUM_account = i;
		return OK;
		}
	}
	return DECLINED_STOLEN_CARD;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	
	if (termData->transAmount > Database[NUM_account].balance) {
		return LOW_BALANCE;
	}
	else
	{
		return OK;
	}

}



EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	
	transData->cardHolderData = card_Data;
	transData->terminalData = terminal_Data;

	int valid = isValidAccount(&transData->cardHolderData);
	if (valid == DECLINED_STOLEN_CARD) {
		transData->transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	else {
		valid = isAmountAvailable(&transData->terminalData);
		if (valid == LOW_BALANCE) {
			transData->transState = DECLINED_INSUFFECIENT_FUND;
			return DECLINED_INSUFFECIENT_FUND;
		}
		else {
			transData->transState = APPROVED;
			Database[NUM_account].balance -= transData->terminalData.transAmount;
			printf("APPROVED \n");
			printf("New Balance: %f \n", Database[NUM_account].balance);
			return APPROVED;
		}

	}

}


EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	transData->transactionSequenceNumber = seq_num;
	entryData[seq_num - 1] = transaction_Data;
	seq_num++;
}
