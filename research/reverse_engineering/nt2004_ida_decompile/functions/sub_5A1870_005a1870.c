int __thiscall sub_5A1870(void *this, int a2)
{
  int result; // eax
  unsigned int v4; // eax
  void *v5; // eax
  unsigned int v6; // ecx
  _DWORD v7[10]; // [esp+1Ch] [ebp-2E4h] BYREF
  _DWORD v8[16]; // [esp+44h] [ebp-2BCh] BYREF
  _DWORD v9[159]; // [esp+84h] [ebp-27Ch] BYREF

  result = *((_DWORD *)this + 1);
  if ( result <= 0 )
    return result;
  if ( (BYTE1(*(_DWORD *)this) & 0x80u) != 0 )
  {
    v4 = *(_DWORD *)this & 0xFFFF7FFF;
    *(_DWORD *)this = v4;
    if ( (v4 & 1) != 0 )
    {
      v5 = (void *)sub_5A8020(*((_DWORD *)this + 5), 96, 0, 0);
      v6 = 24 * *((_DWORD *)this + 1);
    }
    else
    {
      if ( (v4 & 2) == 0 )
      {
LABEL_8:
        sub_5A80B0(*((_DWORD *)this + 5));
        goto LABEL_9;
      }
      v5 = (void *)sub_5A8020(*((_DWORD *)this + 5), 96, 0, 0);
      v6 = 28 * *((_DWORD *)this + 1);
    }
    qmemcpy(v5, *((const void **)this + 6), v6);
    goto LABEL_8;
  }
LABEL_9:
  if ( !dword_7E8D04 )
    sub_5AB360(0);
  if ( a2 != dword_7E8CDC )
  {
    sub_5B5030(&unk_7E6B48);
    sub_5904C0(v7);
    sub_5B4C70(2, v8);
    v8[0] = 1059256707;
    v8[5] = 1059256707;
    v8[10] = 1038323257;
    v8[11] = 1065353216;
    v8[14] = -1137308831;
    v8[15] = 0;
    sub_5B4C70(4, v8);
    sub_5B4CC0(a2, 1);
    nullsub_10();
  }
  if ( dword_7E8C00 > 1 )
  {
    sub_592FE0(v9);
    sub_593B30((int)v9, *(float *)&dword_7E8C04, 0.0, *(float *)&dword_7E8C08, 1.0, 0);
    sub_5B4E60(v9);
    j_nullsub_6(v9);
  }
  sub_5A8250(
    dword_7E8E5C,
    *((_DWORD *)this + 5),
    0,
    *((_DWORD *)this + 1),
    *((_DWORD *)this + 4),
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    3,
    2);
  if ( !dword_7E8D04 )
    sub_5AB3A0(0);
  result = dword_7E8CDC;
  if ( a2 != dword_7E8CDC )
  {
    sub_5B4CC0(dword_7E8CDC, 1);
    return sub_5B5090(&unk_7E6B48);
  }
  return result;
}
