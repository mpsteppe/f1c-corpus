int sub_4C8CA0()
{
  int v0; // eax
  float *v1; // ecx
  int v2; // edx
  int result; // eax

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_24, 760) )
    DebugLogWrite(&dword_8AD25C, aEnteredSoundPo);
  VirtualCallOnDAT008ac4c4();
  sub_4C7E80((int)&flt_8AC4B0);
  GlobalVirtualDispatchGuarded();
  if ( dword_5EB10C )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 8))(dword_5EB10C) )
    {
      v0 = LODWORD(flt_5EA618[699]);
      if ( v0 > 0 && v0 < 291 )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
    }
  }
  v1 = &flt_5EA618[537];
  v2 = 20;
  do
  {
    result = *(_DWORD *)v1;
    if ( *(int *)v1 > 0 && result < 291 )
      result = StructInitWithSentinelValues(v1);
    v1 += 8;
    --v2;
  }
  while ( v2 );
  return result;
}

