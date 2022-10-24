#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
  public:
    CBeverage(const std::string &description) : m_description(description)
    {
    }

    std::string GetDescription() const override final
    {
        return m_description;
    }

  protected:
    std::string m_description;
};

// Кофе
constexpr unsigned COFEE_PRICE = 60;

class CCoffee : public CBeverage
{
  public:
    CCoffee(const std::string &description = "Coffee") : CBeverage(description)
    {
    }

    double GetCost() const override
    {
        return COFEE_PRICE;
    }
};

enum class MilkShakePortion
{
    Small,
    Medium,
    Large
};

// Молочный коктейль
constexpr unsigned SMALL_MILKSHAKE_PRICE = 50;
constexpr unsigned MEDIUM_MILKSHAKE_PRICE = 60;
constexpr unsigned LARGE_MILKSHAKE_PRICE = 80;

class CMilkshake : public CBeverage
{
  public:
    CMilkshake(MilkShakePortion portionType) : m_cost(), CBeverage("Milkshake")
    {
        switch (portionType)
        {
        case MilkShakePortion::Small:
            m_description = "Small Milkshake";
            m_cost = SMALL_MILKSHAKE_PRICE;
            break;
        case MilkShakePortion::Medium:
            m_description = "Medium Milkshake";
            m_cost = MEDIUM_MILKSHAKE_PRICE;
            break;
        case MilkShakePortion::Large:
            m_description = "Large Milkshake";
            m_cost = LARGE_MILKSHAKE_PRICE;
            break;
        }
    }

    double GetCost() const override
    {
        return m_cost;
    }

  private:
    double m_cost;
};

enum class LattePortion
{
    Standart,
    DoublePortion
};

// Латте
constexpr unsigned STANDART_LATTE_PRICE = 90;
constexpr unsigned DOUBLE_LATTE_PRICE = 130;

class CLatte : public CBeverage
{
  public:
    CLatte(LattePortion portionType = LattePortion::Standart) : m_cost(), CBeverage("Latte")
    {
        switch (portionType)
        {
        case LattePortion::Standart:
            m_description = "Standart latte";
            m_cost = STANDART_LATTE_PRICE;
            break;
        case LattePortion::DoublePortion:
            m_description = "Double Portion latte";
            m_cost = DOUBLE_LATTE_PRICE;
            break;
        }
    }

    double GetCost() const override
    {
        return m_cost;
    }

  private:
    double m_cost;
};

enum class CappuccinoPortion
{
    Standart,
    DoublePortion
};

// Капучино
constexpr unsigned STANDART_CAPPUCINO_PRICE = 80;
constexpr unsigned DOUBLE_CAPPUCINO_PRICE = 120;

class CCappuccino : public CBeverage
{
  public:
    CCappuccino(CappuccinoPortion portionType = CappuccinoPortion::Standart) : m_cost(), CBeverage("Cappuccino")
    {
        switch (portionType)
        {
        case CappuccinoPortion::Standart:
            m_description = "Standart cappuccino";
            m_cost = STANDART_CAPPUCINO_PRICE;
            break;
        case CappuccinoPortion::DoublePortion:
            m_description = "Double Portion cappuccino";
            m_cost = DOUBLE_CAPPUCINO_PRICE;
            break;
        }
    }

    double GetCost() const override
    {
        return m_cost;
    }

  private:
    double m_cost;
};

enum class TeaSort
{
    EarlGrey,
    Сeylon,
    Puer,
    Indian
};

// Чай
constexpr unsigned TEA_PRICE = 30;

class CTea : public CBeverage
{
  public:
    CTea(TeaSort sort) : CBeverage("Tea")
    {
        switch (sort)
        {
        case TeaSort::EarlGrey:
            m_description = "Earl Grey tea";
            break;
        case TeaSort::Indian:
            m_description = "Indian tea";
            break;
        case TeaSort::Puer:
            m_description = "Puer tea";
            break;
        case TeaSort::Сeylon:
            m_description = "Ceylon tea";
            break;
        }
    }

    double GetCost() const override
    {
        return TEA_PRICE;
    }
};
