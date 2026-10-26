int __thiscall sub_598240(void *this, int *a2, char *FileName, int a4)
{
  void *v4; // eax
  int v5; // eax
  float *i; // esi

  dword_7E8E2C = 0;
  Addend = 0;
  dword_7E8E1C = 0;
  if ( dword_7E8E34 && !sub_5B3B20((int)this, FileName, (int)&dword_7E8E1C) )
    dword_7E8E34(16, 0);
  dword_7E8E24 = dword_7E8E1C;
  Addend = dword_7E8E1C / 2;
  InterlockedIncrement(&dword_7E8E2C);
  sub_598180(0);
  v4 = operator new(0x200u);
  if ( v4 )
    v5 = sub_5957F0((int)v4);
  else
    v5 = 0;
  *a2 = v5;
  sub_591CC0(v5);
  *(_DWORD *)(*a2 + 240) |= a4;
  sub_590140(2, 0);
  if ( sub_595C90((_BYTE *)*a2, FileName) )
  {
    sub_591D20(*a2);
    return -1;
  }
  else
  {
    Addend += *(_DWORD *)(*(_DWORD *)(*a2 + 276) + 20)
            + *(_DWORD *)(*(_DWORD *)(*a2 + 276) + 24)
            + *(_DWORD *)(*(_DWORD *)(*a2 + 276) + 28)
            + *(_DWORD *)(*(_DWORD *)(*a2 + 276) + 32);
    dword_7E8E28 = Addend;
    InterlockedIncrement(&dword_7E8E2C);
    sub_598180(0);
    if ( sub_596220((_DWORD *)*a2) )
    {
      sub_591D20(*a2);
      *a2 = 0;
      return -1;
    }
    else
    {
      for ( i = *(float **)(*a2 + 260); i; i = (float *)*((_DWORD *)i + 65) )
      {
        sub_5943E0(i);
        sub_594530(i);
        sub_594600(i);
        sub_5946C0(i);
        sub_5946F0(i);
      }
      InterlockedIncrement(&dword_7E8E2C);
      sub_598180(0);
      sub_590140(1, 0);
      return 0;
    }
  }
}
