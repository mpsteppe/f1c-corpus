int __thiscall sub_49EFA0(void *this)
{
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_16, 2616) )
    DebugLogWrite(&dword_8AD25C, aEnteredOnscree_1);
  RaceInitWithConstants(&dword_8AD298, this);
  if ( dword_5C329C > 0 )
    CockpitDashboardLEDGaugeSetup(&dword_7CE058);
  DoubleDelegateCall_bbe0(&dword_7CD204);
  return sub_49B0A0();
}

