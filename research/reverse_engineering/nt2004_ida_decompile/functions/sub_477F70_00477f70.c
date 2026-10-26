char __thiscall sub_477F70(int this, char a2, int a3)
{
  int v4; // ebx
  int v5; // eax
  int v6; // ebp
  bool v7; // zf
  int v8; // ecx
  char v9; // cl
  int v11; // [esp-4h] [ebp-6Ch]
  int v12; // [esp+10h] [ebp-58h] BYREF
  int v13; // [esp+14h] [ebp-54h]
  char v14[77]; // [esp+18h] [ebp-50h] BYREF
  __int16 v15; // [esp+65h] [ebp-3h]
  char v16; // [esp+67h] [ebp-1h]

  v4 = sub_49FB50();
  LOBYTE(v5) = a2;
  if ( a2 )
    *(_DWORD *)(this + 552) = 1;
  if ( v4 >= 0 && v4 < dword_769E78 )
  {
    v5 = (int)sub_457C50(&ppvOut, v4);
    v6 = v5;
    if ( v5 )
    {
      v14[0] = byte_629120;
      memset(&v14[1], 0, 0x4Cu);
      v15 = 0;
      v16 = 0;
      if ( *(_DWORD *)(this + 552) == 1 )
      {
        v8 = *(_DWORD *)(this + 48);
        *(_DWORD *)(this + 544) = v4;
        *(_DWORD *)(this + 548) = sub_4AD7F0(v8);
        sub_4AD720(aPopupControlSe, 1);
        *(_BYTE *)(*(_DWORD *)(this + 48) + 400) = 0;
        v5 = v6;
        do
        {
          v9 = *(_BYTE *)v5;
          *(_BYTE *)(this + 416 - v6 + v5) = *(_BYTE *)v5;
          ++v5;
        }
        while ( v9 );
        *(_DWORD *)(this + 564) = 1;
        *(_DWORD *)(this + 552) = 2;
      }
      else if ( *(_DWORD *)(this + 552) == 2 )
      {
        v11 = *(_DWORD *)(this + 564);
        v12 = 0;
        v13 = 89;
        LOBYTE(v5) = sub_457310(&ppvOut, v14, &v12, v11);
        *(_DWORD *)(this + 564) = 0;
        if ( (_BYTE)v5 )
        {
          v7 = v12 == 0;
          v5 = v13;
          *(_DWORD *)(this + 552) = 3;
          if ( v7 )
          {
            v5 = sub_457200(v5);
            if ( v5 != 89 )
            {
              if ( v5 >= 0 )
              {
                v5 = v13;
              }
              else
              {
                if ( sub_41F230(dword_62A170, aReservedKey, Destination) )
                {
                  strncpy(Destination, aReservedKey, 0x1FFu);
                  byte_62A37B = 0;
                }
                sub_4AE980(Destination);
                v5 = 89;
                *(_DWORD *)(this + 552) = 2;
              }
            }
          }
          *(_DWORD *)(this + 556) = v12;
          *(_DWORD *)(this + 560) = v5;
        }
      }
      else
      {
        v5 = *(_DWORD *)(this + 552) - 3;
        if ( *(_DWORD *)(this + 552) == 3 )
        {
          sub_477B90((int *)this);
          *(_BYTE *)(*(_DWORD *)(this + 48) + 400) = 1;
          sub_4AE8F0(1);
          LOBYTE(v5) = sub_4AD720(*(char **)(this + 548), 1);
          *(_DWORD *)(this + 552) = 0;
        }
      }
    }
  }
  return v5;
}
