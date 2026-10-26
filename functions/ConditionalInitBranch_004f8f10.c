void __thiscall sub_4F8F10(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax

  if ( *this )
  {
    v3 = this[6];
    this[1] = a2;
    HighResolutionTimerReset(v3);
    this[3] = 0;
    if ( !a2 )
    {
      v4 = WideStringLinkedListSearch(aFtframerate);
      if ( v4 )
        ConditionalUICleanupDispatch(v4);
    }
  }
}
