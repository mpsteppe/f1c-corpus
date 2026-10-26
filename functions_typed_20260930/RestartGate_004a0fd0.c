// RestartGate: byte_7CE25D -> return 4 (mini-restart with cleanup), byte_7CE25E -> return 6 (full restart, no cleanup). byte_7CE25F unused here.
int RestartGate()
{
  int i; // esi
  int result; // eax
  int v2; // ecx
  double v3; // st7
  int v4; // esi
  __int16 *v5; // edi

  if ( byte_7CE25D )
  {
    byte_7CE25D = 0;
    if ( dword_7C56A4 == 7 )
    {
      for ( i = 0; i < dword_5C329C; ++i )
        FieldCopy_c330((_DWORD *)(LODWORD(dword_7C54F0[i]) + 16436));
    }
    if ( ScoringGateCheck() )
    {
      if ( *(_DWORD *)(dword_7C54E8 + 13000) == 1 )
        SessionStateTransition((float *)(dword_7C54E8 + 12), 0, 0);
    }
    return 4;
  }
  if ( byte_7CE25E || byte_7CE260 )
  {
    byte_7CE25E = 0;
    return 6;
  }
  if ( dword_7CE264 == 1 )
  {
    if ( dword_7CE258 != 1 )
      goto LABEL_18;
    return 6;
  }
  sub_404B60((void **)&dword_5EA43C);
  if ( !byte_7CE254 )
    goto LABEL_18;
  v2 = dword_7CE250++;
  result = sub_485B90(v2, byte_7CE25F);
  if ( result == -1 || result == 3 )
    return 6;
  if ( result == 4 )
    return result;
LABEL_18:
  if ( byte_7CE269 && (v3 = *(float *)&dword_7CE26C - dbl_8AFE98, *(float *)&dword_7CE26C = v3, v3 <= 0.0) )
  {
    byte_7CE269 = 0;
    dword_7CE26C = 0;
    dword_7CE258 = 1;
  }
  else if ( dword_7CE258 != 1 )
  {
    if ( dword_7CE258 == 2 )
      dword_7CE258 = 1;
    goto LABEL_27;
  }
  if ( dword_7CE264 == 1 )
    dword_7C569C = 6;
  else
    ConditionalInitGuard();
LABEL_27:
  if ( !byte_7CE254 )
  {
    v4 = 0;
    if ( dword_7CB218 > 0 )
    {
      v5 = word_7CB21C;
      do
      {
        if ( *v5 == 1 )
        {
          if ( ByteFieldExtractorWithShift(&dword_5EA43C) )
          {
            dword_7C569C = 6;
            MainMenuTransition(&dword_5EA43C);
          }
          else
          {
            dword_7CE258 = 1;
          }
        }
        ++v4;
        ++v5;
      }
      while ( v4 < dword_7CB218 );
    }
  }
  sub_4A0CB0();
  return dword_7C569C;
}

