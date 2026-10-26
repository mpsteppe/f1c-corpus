char __thiscall sub_4637A0(_DWORD *this)
{
  char result; // al
  void *v3; // ecx
  int v4; // ebp
  int v5; // eax
  char v6; // cl
  double v7; // st7
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int *v11; // esi
  char *v12; // edi
  float v13; // [esp+0h] [ebp-100h]
  float v14; // [esp+18h] [ebp-E8h]
  int v15; // [esp+1Ch] [ebp-E4h]
  int v16; // [esp+20h] [ebp-E0h]
  int v17; // [esp+24h] [ebp-DCh]
  float v18; // [esp+28h] [ebp-D8h]
  _BYTE v19[8]; // [esp+2Ch] [ebp-D4h] BYREF
  _BYTE v20[76]; // [esp+34h] [ebp-CCh] BYREF
  _BYTE v21[128]; // [esp+80h] [ebp-80h] BYREF

  result = 0;
  if ( *(_BYTE *)(*this + 198) )
  {
    dword_7D0410 = 5;
    if ( dword_7D0418 <= 5 )
    {
      if ( dword_7D041C < 5 )
        dword_7D0410 = dword_7D041C;
    }
    else
    {
      dword_7D0410 = dword_7D0418;
    }
    sub_57A920(*(_DWORD *)(*this + 16312));
    v16 = sub_463750(this, 0);
    if ( sub_462CE0(v3, *this + 200, v16) )
    {
      if ( sub_497940(aAutojoinWaitPa, -1) )
      {
        sub_568BA0(v20);
        sub_568BE0(1);
        sub_568C60(v20);
        v14 = 0.0;
        v4 = 0;
        v15 = 1;
        while ( 1 )
        {
          if ( sub_423A00(byte_5EC4C0, aJoiningSession, byte_5EC4CC) )
          {
            v5 = 0;
            do
            {
              v6 = aJoiningSession[v5];
              byte_5EC4CC[v5++] = v6;
            }
            while ( v6 );
          }
          sub_566650(byte_5EC4CC);
          sub_5665B0(asc_5C65C4);
          v19[0] = 0;
          v7 = sub_568D90(v20);
          v8 = sub_587BDC(flt_7D0F28 - v7);
          sub_58815F(v19, "%d", v8);
          sub_5665B0(v19);
          v13 = dbl_8AFE90;
          sub_4537B0((int)&ppvOut, v13);
          v9 = v4;
          LOBYTE(v10) = 0;
          ++v4;
          sub_485B90(v9, v10);
          sub_4F9AD0(&unk_8AFE18);
          sub_4A1830(&unk_7CE2A4);
          if ( dword_5CC9E8 == -1 )
            goto LABEL_32;
          v18 = sub_568CF0(v20);
          if ( sub_461CD0(this) == 3 )
          {
            if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 7303) )
              sub_4D7AA0(&unk_8AD25C, aAutojoinAttemp);
            sub_461550(v21);
            if ( sub_4630D0(dword_7CD25C, (int)v21) )
            {
              sub_4B1600(&unk_7CE498);
              sub_461900((int)v21);
              v11 = (int *)&unk_5EC6E4;
              do
              {
                sub_4EF5A0(-1, 0);
                v11 += 4656;
              }
              while ( (int)v11 < (int)&dword_7C54E4 );
              dword_5C329C = 0;
              sub_42BC80();
              byte_7C5690 = 1;
              dword_7C56A0 = 2;
              sub_4A0AF0(&unk_7CE24C);
              sub_497940(aClientTeamSele, -1);
              nullsub_3(v20);
              return 1;
            }
          }
          else if ( sub_568D90(v20) > flt_7D0F28 || (v17 = sub_462D30(this, 0)) != 0 )
          {
            v12 = sub_462DA0(5);
            if ( sub_423A00(byte_5EC4C0, v12, byte_5EC4CC) )
            {
              if ( v12 )
                strcpy(byte_5EC4CC, v12);
              else
                byte_5EC4CC[0] = 0;
            }
            sub_466080(byte_5EC4CC);
            if ( v17 != 3 )
            {
              sub_497940(aAutojoinFailur, -1);
              sub_497250(1);
LABEL_32:
              nullsub_3(v20);
              return 0;
            }
          }
          if ( v14 > 10.0 )
          {
            sub_462CE0(this, *this + 200, v16);
            ++v15;
            v14 = 0.0;
          }
          v14 = v18 + v14;
        }
      }
      if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 7381) )
      {
        sub_4D7AA0(&unk_8AD25C, aCouldNotSwitch);
        return 0;
      }
    }
    else if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 7387) )
    {
      sub_4D7AA0(&unk_8AD25C, aCouldNotAutojo);
    }
    return 0;
  }
  return result;
}
