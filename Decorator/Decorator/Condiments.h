#pragma once
#pragma once
#include "stdafx.h"

#include "IBeverage.h"

// ������� ��������� "������� � �������". ����� �������� ��������
class CCondimentDecorator : public IBeverage
{
  public:
    std::string GetDescription() const override
    {
        // �������� ��������������� ������� ����������� � �������� �������������� �������
        return m_beverage->GetDescription() + ", " + GetCondimentDescription();
    }

    double GetCost() const override
    {
        // ��������� ������������ �� ��������� ������� � ��������� ������������� �������
        return m_beverage->GetCost() + GetCondimentCost();
    }

    // ��������� � �������� ������� ����������� � ������� ���������� �����������
    virtual std::string GetCondimentDescription() const = 0;
    virtual double GetCondimentCost() const = 0;

  protected:
    CCondimentDecorator(IBeveragePtr &&beverage) : m_beverage(move(beverage))
    {
    }

  private:
    IBeveragePtr m_beverage;
};

// ������� �� ������
constexpr unsigned CINNAMON_PRICE = 20;
class CCinnamon : public CCondimentDecorator
{
  public:
    CCinnamon(IBeveragePtr &&beverage) : CCondimentDecorator(move(beverage))
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return CINNAMON_PRICE;
    }

    std::string GetCondimentDescription() const override
    {
        return "Cinnamon";
    }
};

// �������� �������
constexpr unsigned LEMON_PRICE = 20;
class CLemon : public CCondimentDecorator
{
  public:
    CLemon(IBeveragePtr &&beverage, unsigned quantity = 1) : CCondimentDecorator(move(beverage)), m_quantity(quantity)
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return LEMON_PRICE * m_quantity;
    }
    std::string GetCondimentDescription() const override
    {
        return "Lemon x " + std::to_string(m_quantity);
    }

  private:
    unsigned m_quantity;
};

enum class IceCubeType
{
    Dry,  // ����� ��� (��� ������� ��������� �������)
    Water // ������� ������ �� ����
};

constexpr unsigned DRY_ICE_PRICE = 10;
constexpr unsigned WATER_ICE_PRICE = 5;

// ������� "������ ����". ������������ ����� � ����������� �������, ��� ������ �� ���������
// � ��������
class CIceCubes : public CCondimentDecorator
{
  public:
    CIceCubes(IBeveragePtr &&beverage, unsigned quantity, IceCubeType type = IceCubeType::Water)
        : CCondimentDecorator(move(beverage)), m_quantity(quantity), m_type(type)
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        // ��� ������ �������, ��� ������ ���������.
        // ����� ��� ����� ������
        return (m_type == IceCubeType::Dry ? DRY_ICE_PRICE : WATER_ICE_PRICE) * m_quantity;
    }
    std::string GetCondimentDescription() const override
    {
        return std::string(m_type == IceCubeType::Dry ? "Dry" : "Water") + " ice cubes x " + std::to_string(m_quantity);
    }

  private:
    unsigned m_quantity;
    IceCubeType m_type;
};

// ��� ������
enum class SyrupType
{
    Chocolate, // ����������
    Maple,     // ��������
};

// ������� "�����"
constexpr unsigned SYRUP_PRICE = 15;

class CSyrup : public CCondimentDecorator
{
  public:
    CSyrup(IBeveragePtr &&beverage, SyrupType syrupType) : CCondimentDecorator(move(beverage)), m_syrupType(syrupType)
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return SYRUP_PRICE;
    }
    std::string GetCondimentDescription() const override
    {
        return std::string(m_syrupType == SyrupType::Chocolate ? "Chocolate" : "Maple") + " syrup";
    }

  private:
    SyrupType m_syrupType;
};

// ���������� ������
constexpr unsigned CHOCOLATE_CRUMBS_PRICE = 2;

class CChocolateCrumbs : public CCondimentDecorator
{
  public:
    CChocolateCrumbs(IBeveragePtr &&beverage, unsigned mass) : CCondimentDecorator(move(beverage)), m_mass(mass)
    {
    }

    double GetCondimentCost() const override
    {
        return CHOCOLATE_CRUMBS_PRICE * m_mass;
    }

    std::string GetCondimentDescription() const override
    {
        return "Chocolate crumbs " + std::to_string(m_mass) + "g";
    }

  private:
    unsigned m_mass;
};

// ��������� �������
constexpr unsigned COCOUNT_FLAKES_PRICE = 1;

class CCoconutFlakes : public CCondimentDecorator
{
  public:
    CCoconutFlakes(IBeveragePtr &&beverage, unsigned mass) : CCondimentDecorator(move(beverage)), m_mass(mass)
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return COCOUNT_FLAKES_PRICE * m_mass;
    }
    std::string GetCondimentDescription() const override
    {
        return "Coconut flakes " + std::to_string(m_mass) + "g";
    }

  private:
    unsigned m_mass;
};

// ������
constexpr unsigned CREAM_PRICE = 25;

class CCream : public CCondimentDecorator
{
  public:
    CCream(IBeveragePtr &&beverage) : CCondimentDecorator(move(beverage))
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return CREAM_PRICE;
    }
    std::string GetCondimentDescription() const override
    {
        return "Cream";
    }
};

// �������
constexpr unsigned MAX_CHOCOLATE_AMOUNT = 5;
constexpr unsigned CHOCOLATE_PRICE = 10;

class CChocolate : public CCondimentDecorator
{
  public:
    CChocolate(IBeveragePtr &&beverage, unsigned amount)
        : CCondimentDecorator(move(beverage)), m_amount(std::min(amount, MAX_CHOCOLATE_AMOUNT))
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return CHOCOLATE_PRICE * m_amount;
    }
    std::string GetCondimentDescription() const override
    {
        return std::to_string(m_amount) + " slices of chocolate ";
    }

  private:
    unsigned m_amount;
};

enum class LiquorType
{
    Nut,
    Chocolate
};

// ����
constexpr unsigned LYQUOR_PRICE = 50;

class CLiquor : public CCondimentDecorator
{
  public:
    CLiquor(IBeveragePtr &&beverage, LiquorType type) : CCondimentDecorator(move(beverage)), m_type(type)
    {
    }

  protected:
    double GetCondimentCost() const override
    {
        return LYQUOR_PRICE;
    }
    std::string GetCondimentDescription() const override
    {
        return std::string(m_type == LiquorType::Nut ? "Nut" : "Chocolate") + " liquor";
    }

  private:
    LiquorType m_type;
};
