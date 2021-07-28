/*
 * Singleton.h
 *
 *  Created on: 2021. 7. 14.
 *      Author: dhjeong
 */

#ifndef CREATIONAL_SINGLETON_CONFIGURATION_H_
#define CREATIONAL_SINGLETON_CONFIGURATION_H_

#include <string>

class Configuration {
public:
	/**
	 * 이 부분은 구현 방식에 따라 달라질 수 있는데, 나는 이 방식을 주로 사용한다.
	 * static 변수의 특징은 프로세스 시작 시점에 바로 메모리에 올라온다는 점인데,
	 * 이 특징을 사용하여 getInstance() 함수처럼 instance에 대한 반환을 요청하지 않아도 되고,
	 * getInsatnce()를 호출할 때마다 instance의 생성 여부를 확인하는 단점을 해소할 수도 있기 때문이다.
	 *
	 * 물론 프로세스 시작 이후 한 번도 호출되지 않을 경우 불필요한 메모리 공간을 낭비한다는 단점은 있지만,
	 * 동시 접근 문제로 인한 골치를 해결할 수 있다는 것을 더 큰 이점으로 생각하고 이 방법을 주로 사용하는 편이다
	 */
	static Configuration instance;

public:
	/**
	 * singleton 객체를 참조하는 곳에서 호출할 수 있는 멤버함수를 정의한다
	 */
	int getReadCount();
//	std::string getTargetFileName();
	void getTargetFileName(std::string& targetFileName);
	int getTargetPos();

private:
	/**
	 * 외부에서 객체 생성을 임의로 할 수 없도록, 생성자와 소멸자는 private으로 지정한다
	 */

	/**
	 * 생성자
	 * 생성자는 당연히 매개변수가 없다
	 * 매개변수가 필요하다는 것은, 생성되는 객체마다 다른 데이터가 지정되어야 한다는 의미인데
	 * 그건... singleton을 쓰는 메리트가 없지 않을까?
	 */
	Configuration();

	/**
	 * 객체 생성 시점에 필요한 경우 init을 진행할 수도 있다
	 */
	void init();

	/**
	 * 소멸자
	 */
	virtual ~Configuration();

private:
	// 멤버 변수 정의
	int m_readCount;
	std::string m_targetFileName;
	int m_targetPos;
};

#endif /* CREATIONAL_SINGLETON_CONFIGURATION_H_ */
