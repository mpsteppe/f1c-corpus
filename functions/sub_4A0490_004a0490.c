int sub_4A0490()
{
  char *v0; // eax
  char **v1; // eax
  char **v2; // esi
  char *v3; // eax

  if ( dword_7C569C == 5 )
  {
    dword_5CC9E8 = 3;
    sub_42D210(&dword_7C569C, 0);
  }
  switch ( dword_7D0410 )
  {
    case 4:
      sub_4B0770(0);
      v0 = (char *)dword_7CE630;
      if ( !dword_7CE630 )
        v0 = byte_5EA438;
      if ( *v0 )
      {
        v1 = (char **)ConditionalDispatch_40b0(v0);
        v2 = v1;
        if ( v1 )
        {
          v3 = *v1;
          if ( !*v2 )
            v3 = byte_5EA438;
          StringCopyWithBufferRealloc(v3);
          StringCopyWithBufferRealloc(v2 + 47);
        }
      }
      break;
    case 5:
      ShortComputation_3140(dword_7CD25C);
      break;
    case 6:
      dword_7D0410 = 1;
      if ( dword_7D0418 <= 1 )
      {
        if ( dword_7D041C < 1 )
          dword_7D0410 = dword_7D041C;
      }
      else
      {
        dword_7D0410 = dword_7D0418;
      }
      break;
  }
  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  SeasonScoringReset();
  LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMainMenu, -1);
  return 0;
}
