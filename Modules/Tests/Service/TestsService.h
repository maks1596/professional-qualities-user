#pragma once

#include <QList>

#include "BaseModel/BaseModel.h"

class Test;
class TestWithStatus;

class TestsService : public BaseService {
Q_OBJECT
public:
    TestsService(QObject *parent = nullptr);

	void getTests(int userId) const;
	void getTest(int testId) const;

signals:
	void testsGot(const QList<TestWithStatus> &tests);
	void testGot(const Test &test);

private slots:
	void jsonTestsGot(const QJsonArray &jsonTests);
	void jsonTestGot(const QJsonObject &jsonTest);
};
