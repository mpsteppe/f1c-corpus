void *__thiscall sub_530E40(float *this)
{
  int v1; // edi
  int v3; // ebp
  int v4; // esi
  int v5; // eax
  double v6; // st7
  double v7; // st6
  int v8; // eax
  void *result; // eax
  int v10; // [esp+8h] [ebp-4h]

  v1 = 0;
  byte_FADE3C = 1;
  v10 = dword_757C10;
  if ( dword_757C10 > 0 )
  {
    v3 = (char *)this - (char *)&dword_91E088;
    do
    {
      v4 = *(&dword_91E088 + v1);
      v5 = *(_DWORD *)(v4 + 19380);
      if ( v5 != 3 && v5 != 2 )
      {
        if ( *(float *)(v3 + 4 * v1 + 9560200) > 0.0 )
        {
          v6 = *(float *)(v3 + 4 * v1 + 9560200) - *(float *)(v3 + 4 * v1 + 9560616);
          ++*(_DWORD *)(v4 + 19284);
          v7 = v6 + this[213];
          if ( v7 < 0.0 )
            v7 = 0.0;
          *(float *)(v4 + 19432) = v7;
          *(float *)(v4 + 19464) = this[213] - flt_FADE1C + v6;
          sub_52D900((_DWORD *)(v4 + 19272));
          sub_530CE0(v4);
        }
        v8 = *(&dword_91E088 + v1);
        if ( !*(_DWORD *)(v8 + 19380) )
          sub_52D900((_DWORD *)(v8 + 19272));
      }
      ++v1;
    }
    while ( v1 < v10 );
  }
  off_82F49C = &unk_75B494;
  off_82F498 = &unk_75B494;
  off_82F494 = &unk_75B494;
  result = &unk_82F4A4;
  dword_75B490 = 0;
  off_9034AC = &unk_82F4A4;
  off_9034A8 = &unk_82F4A4;
  off_9034A4 = (int)&unk_82F4A4;
  dword_82F4A0 = 0;
  return result;
}
