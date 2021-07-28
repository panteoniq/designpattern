/*
 * Singleton.cpp
 *
 *  Created on: 2021. 7. 14.
 *      Author: dhjeong
 */

#include "Configuration.h"

// 이 코드를 반드시 cpp 파일에 추가해야 오류가 발생하지 않는다
Configuration Configuration::instance;

/**
 * 생성자
 */
Configuration::Configuration() {
	m_readCount = 0;
	m_targetPos = 0;
}

/**
 * 소멸자
 */
Configuration::~Configuration() {
}

/**
 * 초기화 함수
 */
void Configuration::init() {
	// 필요한 초기화 동작을 수행하면 된다

	// TODO
	m_readCount = 1;
	m_targetPos = 10;
	m_targetFileName = "testfile.txt";
}

/**
 * getter
 */
int Configuration::getReadCount() {
	return m_readCount;
}

void Configuration::getTargetFileName(std::string &targetFileName) {
	targetFileName.clear();
	targetFileName = m_targetFileName;
}

int Configuration::getTargetPos() {
	return m_targetPos;
}

