/**
 * Control nRF52-DK's LED with BLE
 *
 * TODO: Author:
 * License: MIT
 */

#include <Arduino.h>
#include <BLEPeripheral.h>

BLEPeripheral ledPeripheral = BLEPeripheral();

BLEService ledService = BLEService("19b10000e8f2537e4f6cd104768a1214");
BLECharCharacteristic ledCharacteristic =
    BLECharCharacteristic("19b10001e8f2537e4f6cd104768a1214",
                          BLERead | BLEWrite);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    ledPeripheral.setAdvertisedServiceUuid(ledService.uuid());
    ledPeripheral.addAttribute(ledService);
    ledPeripheral.addAttribute(ledCharacteristic);
    ledPeripheral.setLocalName("Nordic NRF52 DK");
    ledPeripheral.begin();
}

void loop() {
    BLECentral central = ledPeripheral.central();

    if (central) {
        while (central.connected()) {
            if (ledCharacteristic.written()) {
                if (ledCharacteristic.value()) {
                    digitalWrite(LED_BUILTIN, HIGH);
                } else {
                    digitalWrite(LED_BUILTIN, LOW);
                }
            }
        }
    }
}