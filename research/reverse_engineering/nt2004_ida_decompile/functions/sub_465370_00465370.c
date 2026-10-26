char __thiscall sub_465370(void *this)
{
  char result; // al
  void *v3; // ecx
  int v4; // ebp
  double v5; // st7
  int v6; // ecx
  int v7; // edx
  char *v8; // esi
  char *v9; // edi
  float v10; // [esp+0h] [ebp-DCh]
  char v11; // [esp+8h] [ebp-D4h]
  float v12; // [esp+18h] [ebp-C4h]
  char ArgList; // [esp+1Ch] [ebp-C0h]
  CHAR *v14; // [esp+20h] [ebp-BCh]
  int v15; // [esp+24h] [ebp-B8h]
  float v16; // [esp+28h] [ebp-B4h]
  char Buffer[8]; // [esp+2Ch] [ebp-B0h] BYREF
  _BYTE v18[76]; // [esp+34h] [ebp-A8h] BYREF
  _BYTE v19[92]; // [esp+80h] [ebp-5Ch] BYREF

  result = 0;
  if ( *(_BYTE *)(*(_DWORD *)this + 165) )
  {
    *(_DWORD *)dword_7689CC = 5;
    if ( dword_7689D4 <= 5 )
    {
      if ( dword_7689D8 < 5 )
        *(_DWORD *)dword_7689CC = dword_7689D8;
    }
    else
    {
      *(_DWORD *)dword_7689CC = dword_7689D4;
    }
    sub_56A650(*(_DWORD *)(*(_DWORD *)this + 6708));
    v14 = sub_465270(this);
    if ( sub_4646E0(v3, *(_DWORD *)this + 167, (int)v14) )
    {
      if ( sub_4AD720(aAutojoinWaitPa, 1) )
      {
        sub_57B5D0(v18);
        sub_57B610(1);
        sub_57B690(v18);
        v12 = 0.0;
        v4 = 0;
        ArgList = 1;
        while ( 1 )
        {
          if ( sub_41F230(dword_62A170, aJoiningSession, Destination) )
          {
            strncpy(Destination, aJoiningSession, 0x1FFu);
            byte_62A37B = 0;
          }
          sub_578600(Destination);
          sub_578560(asc_6005F8);
          Buffer[0] = 0;
          v5 = flt_7698FC - sub_57B7C0(v18);
          sprintf(Buffer, "%d", (unsigned int)(__int64)v5);
          sub_578560(Buffer);
          v10 = dbl_7DA9C0;
          sub_455D30((int)&ppvOut, v10);
          v6 = v4;
          LOBYTE(v7) = 0;
          ++v4;
          sub_49C1D0(v6, v7);
          sub_527300(&unk_7DA938);
          sub_4BB880(&unk_7661CC);
          if ( dword_608F60 == -1 )
            goto LABEL_31;
          v16 = sub_57B720(v18);
          if ( sub_4633A0((int *)this) == 3 )
          {
            if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 8181) )
              sub_500FE0((int)&unk_7D7920, aAutojoinAttemp, ArgList);
            sub_462C80(v19);
            if ( sub_464BD0(dword_764D70, (int)v19) )
            {
              sub_462FE0((int)v19);
              v8 = (char *)&unk_62BFBC;
              do
              {
                sub_51BC20(-1, 0);
                v8 += 25304;
              }
              while ( (int)v8 < (int)byte_75483C );
              NumOfElements = 0;
              sub_42DC40();
              byte_75AB9C = 1;
              dword_75CBAC = 2;
              nullsub_6(&byte_766124);
              sub_4AD720(aClientVehicleS, 1);
              nullsub_6(v18);
              return 1;
            }
          }
          else if ( sub_57B7C0(v18) > flt_7698FC || (v15 = sub_464740(this, 0)) != 0 )
          {
            v9 = sub_4647B0(5);
            if ( sub_41F230(dword_62A170, v9, Destination) )
            {
              if ( v9 )
              {
                strncpy(Destination, v9, 0x1FFu);
                byte_62A37B = 0;
              }
              else
              {
                Destination[0] = 0;
              }
            }
            sub_46DFB0(Destination);
            if ( v15 != 3 )
            {
              sub_4AD720(aAutojoinFailur, 1);
              sub_4AD1C0(1);
LABEL_31:
              nullsub_6(v18);
              return 0;
            }
          }
          if ( v12 > 10.0 )
          {
            sub_4646E0(this, *(_DWORD *)this + 167, (int)v14);
            ++ArgList;
            v12 = 0.0;
          }
          v12 = v16 + v12;
        }
      }
      if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 8255) )
      {
        sub_500FE0((int)&unk_7D7920, aCouldNotSwitch, v11);
        return 0;
      }
    }
    else if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 8261) )
    {
      sub_500FE0((int)&unk_7D7920, aCouldNotAutojo, *(_BYTE *)this - 89);
    }
    return 0;
  }
  return result;
}
