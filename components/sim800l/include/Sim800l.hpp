#pragma once

#include <iostream>
#include <initializer_list>

#define SIM800L_DEF_BUF_SIZE         240

typedef enum {
	Sim800lOk = 0,
	Sim800lErr = -1,
    Sim800lRecErr = -2
} Sim800lError;

class Sim800l {
public:
    Sim800l();
    virtual ~Sim800l() = 0;

    virtual Sim800lError execAT() final;

    /* AT+CSQ Signal Quality Report */
    // virtual Sim800lError execCSQ(int & rssi, int & ber) final;

    /* AT+CCID Show ICCID */
    // virtual Sim800lError execCCID(char * ccid) final;

    /* AT+CREG Network Registration */
    // virtual Sim800lError readCREG(unsigned char & n, int & stat) final;

    /* AT+SAPBR Bearer Settings for Applications Based on IP */
    virtual Sim800lError writeSAPBR(const unsigned char cmd_type, const unsigned char cid, const char * ConParamTag, const char * ConParamValue) final;
    virtual Sim800lError writeSAPBR(unsigned char cmd_type, unsigned char cid) final;

    /* AT+HTTPINIT Initialize HTTP Service  */
    virtual int execHTTPINIT() final;

    /* AT+HTTPPARA Set HTTP Parameters Value */
    virtual Sim800lError writeHTTPPARA(const char * HTTPParamTag, const int HTTPParamValue) final;
    virtual Sim800lError writeHTTPPARA(const char * HTTPParamTag, const char * HTTPParamValue) final;

    /* AT+HTTPDATA Input HTTP Data */
    virtual Sim800lError writeHTTPDATA(const int size, const int time, const char * inputData) final;

    /*  AT+HTTPACTION HTTP Method Action 
    *   method =:
    *   - 0 - GET,
    *   - 1 - POST,
    *   - 2 - HEAD.
    */
    virtual Sim800lError writeHTTPACTION(const int method) final;

    /* AT+HTTPREAD Read the HTTP Server Response */
    // virtual int writeHTTPREAD(const int start_address, const int byte_size, char * receivedData) final;
    virtual Sim800lError execHTTPREAD() final;

    /* AT+HTTPTERM Terminate HTTP Service */
    virtual Sim800lError execHTTPTERM() final;

protected:
    // virtual Sim800lError sendData(const char * data, int len);
    virtual Sim800lError sendData(const char * data);
    virtual Sim800lError sendAT(const char * type, std::initializer_list<const char *> params) final;
    virtual Sim800lError sendAT(const char * type) final;
    virtual Sim800lError sendAT() final;
    virtual int receiveData();
    virtual Sim800lError retrieveErr() final;
    virtual Sim800lError sendReceiveRetriveData(const char * data) final;
    virtual void simDelay(int ms);
    // Sim800lError retriveParams(std::initializer_list<const char *> params) final;

    char receivedData[SIM800L_DEF_BUF_SIZE];
    int receivedLen;
};



