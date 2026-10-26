int __thiscall sub_4B1820(int this)
{
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_20, 2463) )
    DebugLogWrite(&dword_8AD25C, aEnteredPlayerf);
  *(_DWORD *)(this + 18864) = &stru_5EC6D8;
  return PlayerNameNeverUsedProfileFileCreateRead((_BYTE *)this);
}

