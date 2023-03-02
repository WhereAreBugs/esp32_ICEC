//
// Created by 神奇bug在哪里 on 2023/3/2.
//
#include "Status.h"

void SYSManeger::setup() {

}

void SYSManeger::loop() {

}

SYSStatus SYSManeger::get_Status() {

    return status;
}

void SYSManeger::set_Status(uint8_t status) {
    this->status.summary = status;

}

