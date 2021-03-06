#pragma once

#include <QAbstractListModel>

#include "Entities/QuestionWithAnswer/QuestionWithAnswer.h"

class Answer;
class Test;

class QuestionsModel : public QAbstractListModel {
    Q_OBJECT

public:
    //  :: Lifecycle ::
    explicit QuestionsModel(const Test &test, QObject *parent = nullptr);

    //  :: QAbstractListModel ::
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    //  :: Accessors ::

    int getTestId() const;
    void setTestId(int testId);

    QString getTestName() const;
    void setTestName(const QString &testName);

    QString getInstruction() const;
    void setInstruction(const QString &instruction);

    const QList<QuestionWithAnswer> &getQuestionsWithAnswer() const;
    QList<QuestionWithAnswer> &getQuestionsWithAnswer();
    void setQuestionsWithAnswer(const QList<QuestionWithAnswer> &questionsWithAnswer);
    void setQuestionsWithAnswer(const Questions &questions);
    void setQuestionsWithAnswer(const Questions &questions,
                                const AnswerOptions &generalAnswerOptions);

    bool areAllQuestionsHaveAnswers() const;
    QList<Answer> getAnswers() const;

#ifdef QT_DEBUG
    void setRandomAnswers();
#endif

private:
    int m_testId;
    QString m_testName;
    QString m_instruction;
    QList<QuestionWithAnswer> m_questionsWithAnswer;
};
