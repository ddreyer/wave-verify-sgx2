#ifndef __ENCLAVEAPP_HPP__
#define __ENCLAVEAPP_HPP__

#ifdef __cplusplus
extern "C" {
#endif
    #include "Enclave_u.h"
    #include <stdlib.h>
    #include <limits.h>
    #include <stdio.h>
    #include <time.h>
    #include <sgx_urts.h>
    #include <sys/stat.h>
    #include <openssl/evp.h>
    #include <getopt.h>
    #include <unistd.h>
    #include <sgx_uae_service.h>
    #include <sgx_ukey_exchange.h>
    #include "common.h"
    #include "protocol.h"
    #include "sgx_detect.h"
    #include "hexutil.h"
    #include "fileio.h"
    #include "base64.h"
    #include "crypto.h"
    #include "logfile.h"
    #include "settings.h"

    int file_in_searchpath (const char *file, const char *search, char *fullpath,
	size_t len);

    sgx_status_t sgx_create_enclave_search (
        const char *filename,
        const int edebug,
        sgx_launch_token_t *token,
        int *updated,
        sgx_enclave_id_t *eid,
        sgx_misc_attribute_t *attr
    );

    long verify(char *proof_cipher, size_t proof_cipher_size, char *subject, 
	    size_t subj_size, char *policyDER, size_t policyDER_size);

    int provision_key(char *key, char *iv);
    
    int init_enclave();

    int destroy_enclave();

    int generate0and1();

    int do_attestation(sgx_enclave_id_t eid);
    
#ifdef __cplusplus
}
#endif

#endif




