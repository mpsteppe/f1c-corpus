int sub_503880()
{
  int result; // eax
  int v1; // ebx
  int v2; // eax
  char v3; // [esp+8h] [ebp-100h] BYREF
  _BYTE v4[124]; // [esp+9h] [ebp-FFh] BYREF
  __int16 v5; // [esp+85h] [ebp-83h]
  char v6; // [esp+87h] [ebp-81h]
  char Buffer[125]; // [esp+88h] [ebp-80h] BYREF
  __int16 v8; // [esp+105h] [ebp-3h]
  char v9; // [esp+107h] [ebp-1h]

  if ( !sub_4B2FB0() && !sub_4B2FD0() )
    sub_4B2FE0();
  sub_506960(dword_7E8CDC);
  result = sub_506960(dword_7E8CDC);
  if ( dword_75AAC4 )
  {
    result = dword_75AAC4 + 24772;
    v1 = dword_75AAC4 + 20836;
    if ( dword_75AAC4 != -24772 )
      result = sub_501610(dword_75AAC4 + 24772, 240, 59, 0xFFFFFF, 0, 1, 0.80000001, 0.80000001);
    if ( v1 )
    {
      Buffer[0] = byte_629120;
      memset(&Buffer[1], 0, 0x7Cu);
      v8 = 0;
      v9 = 0;
      v3 = byte_629120;
      memset(v4, 0, sizeof(v4));
      v5 = 0;
      v6 = 0;
      sub_4B3160(&v3, 127);
      sprintf(Buffer, "PREV LAP %s", &v3);
      sub_501610((int)Buffer, 224, 93, 0xFFFFFF, 0, 1, 0.80000001, 0.80000001);
      v3 = byte_629120;
      memset(v4, 0, sizeof(v4));
      v5 = 0;
      v6 = 0;
      v2 = *(_DWORD *)(v1 + 48);
      if ( v2 <= 0 )
        sprintf(&v3, "POS -/%d", NumOfElements);
      else
        sprintf(&v3, "POS %d/%d", v2, NumOfElements);
      return sub_501610((int)&v3, 208, 126, 0xFFFFFF, 0, 1, 0.80000001, 0.80000001);
    }
  }
  return result;
}
