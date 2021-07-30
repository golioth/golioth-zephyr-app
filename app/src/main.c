/*
 * Copyright (c) 2021 Golioth, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(golioth_logging, LOG_LEVEL_DBG);

#include <net/coap.h>
#include <net/golioth/system_client.h>
#include <net/golioth/wifi.h>

static struct golioth_client *client = GOLIOTH_SYSTEM_CLIENT_GET();

static void golioth_on_message(struct golioth_client *client,
                   struct coap_packet *rx)
{
    uint16_t payload_len;
    const uint8_t *payload;
    uint8_t type;

    type = coap_header_get_type(rx);
    payload = coap_packet_get_payload(rx, &payload_len);

    if (!IS_ENABLED(CONFIG_LOG_BACKEND_GOLIOTH) && payload) {
        LOG_HEXDUMP_DBG(payload, payload_len, "Payload");
    }
}

void main(void)
{
    int counter = 0;

    LOG_DBG("Start Logging sample");

    if (IS_ENABLED(CONFIG_GOLIOTH_SAMPLE_WIFI)) {
        LOG_INF("Connecting to WiFi");
        wifi_connect();
    }

    client->on_message = golioth_on_message;
    golioth_system_client_start();

    while (true) {
        LOG_INF("INFO: the counter is %d", counter);

        counter++;

        k_sleep(K_SECONDS(5));
    }
}
