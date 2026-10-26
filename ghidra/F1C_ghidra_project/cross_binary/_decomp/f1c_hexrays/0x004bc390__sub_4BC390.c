// f1c  0x004bc390  size=323
void __thiscall sub_4BC390(float *this, int a2)
{
  int v3; // edi
  bool v4; // zf
  int v5; // edi
  float v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  if ( this[44] > 10.0 )
    return;
  v3 = a2;
  sub_54C150(&a2, 2048);
  switch ( a2 )
  {
    case 0:
      v4 = *((_DWORD *)this + 3) == 2;
LABEL_8:
      if ( !v4 )
        return;
      break;
    case 1:
      v4 = *((_DWORD *)this + 3) == 0;
      goto LABEL_8;
    case 2:
      v4 = *((_DWORD *)this + 3) == 1;
      goto LABEL_8;
  }
  if ( sub_4BC340(this) )
  {
    *(float *)&v7 = sub_4EFBD0(v3);
    if ( *((_DWORD *)this + 24) == 2 )
      v6 = *(float *)&v7 - this[25];
    else
      v6 = -1.0;
    if ( !*(_DWORD *)(*(_DWORD *)this + 13000) && dword_8AD238 )
      sub_4D5900(a2, v7);
    if ( dword_83EE60 >= 1023 )
    {
      v5 = dword_8AAE64;
    }
    else
    {
      ++dword_83EE60;
      v5 = dword_8AAE64;
      dword_8AAE64 += 432;
    }
    sub_4B33B0((_DWORD *)v5, 4, 8, 8, *((_DWORD *)this + 1), v7, a2 == 0);
    *(float *)(v5 + 8) = v6;
    *(_WORD *)(v5 + 12) = a2;
    *(_WORD *)(v5 + 14) = *((_WORD *)this + 4);
    sub_4BC4E0(v6, *(float *)&v7, a2, *((_DWORD *)this + 2));
  }
}
