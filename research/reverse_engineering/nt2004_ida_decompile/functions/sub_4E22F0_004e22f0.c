void *__thiscall sub_4E22F0(float *this)
{
  signed int v1; // edi
  int v3; // ebp
  int v4; // esi
  int v5; // eax
  double v6; // st7
  double v7; // st6
  int v8; // eax
  void *result; // eax
  signed int v10; // [esp+8h] [ebp-4h]

  v1 = 0;
  byte_7D74C8 = 1;
  v10 = NumOfElements;
  if ( (int)NumOfElements > 0 )
  {
    v3 = (char *)this - (char *)dword_75AAD0;
    do
    {
      v4 = dword_75AAD0[v1];
      v5 = *(_DWORD *)(v4 + 20892);
      if ( v5 != 3 && v5 != 2 )
      {
        if ( *(float *)(v3 + 4 * v1 + 7711440) > 0.0 )
        {
          v6 = *(float *)(v3 + 4 * v1 + 7711440) - *(float *)(v3 + 4 * v1 + 7711632);
          ++*(_DWORD *)(v4 + 20848);
          v7 = v6 + this[102];
          if ( v7 < 0.0 )
            v7 = 0.0;
          *(float *)(v4 + 20956) = v7;
          *(float *)(v4 + 20988) = this[102] - flt_7D74BC + v6;
          sub_4DC390((_DWORD *)(v4 + 20836));
          sub_4E2190(v4);
        }
        v8 = dword_75AAD0[v1];
        if ( !*(_DWORD *)(v8 + 20892) )
          sub_4DC390((_DWORD *)(v8 + 20836));
      }
      ++v1;
    }
    while ( v1 < v10 );
  }
  dword_79FC3C = (int)&unk_76BC34;
  dword_79FC38 = (int)&unk_76BC34;
  dword_79FC34 = (int)&unk_76BC34;
  result = &unk_79FC44;
  dword_76BC30 = 0;
  dword_7D3C4C = (int)&unk_79FC44;
  dword_7D3C48 = (int)&unk_79FC44;
  dword_7D3C44 = (int)&unk_79FC44;
  dword_79FC40 = 0;
  return result;
}
