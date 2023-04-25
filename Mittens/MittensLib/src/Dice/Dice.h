#pragma once

#include "Core.h"
#include <vector>

namespace Mittens
{
	enum DiceType
	{
		D4    = 4,
		D6    = 6,
		D8    = 8,
		D10   = 10,
		D12   = 12,
		D20   = 20,
		D100  = 100,
	};

	class Dice
	{
	public:
		virtual bool IsSpecialDice() const = 0;
	protected:
		Dice(DiceType diceType) { m_Faces = diceType; }
		DiceType m_Faces;
	};

	class MTS_API CommonDice : public Dice
	{
	public:

		virtual bool IsSpecialDice() const override { return false; }
	protected:
		CommonDice(DiceType diceType)
			: Dice(diceType) 
		{ }
	};

	class MTS_API SpecialDice : public Dice
	{
	public:
		virtual bool IsSpecialDice() const override { return true; }
	protected:
		SpecialDice(DiceType diceType)
			: Dice(diceType)
		{ }
		std::vector<SpecialFace> m_SpecialFaces;
	};

	class MTS_API SpecialFace
	{
	protected:
		SpecialFace() { }
		int m_MappedNumber;
	};
}