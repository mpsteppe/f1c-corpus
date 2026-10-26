char *__cdecl sub_55561A(jmp_buf Buf)
{
  unsigned int v1; // eax
  int v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  char v8; // cl
  char v9; // cl
  int v10; // ecx
  char *v11; // eax
  char *result; // eax
  unsigned int v13; // [esp-14h] [ebp-1Ch]

  Buf[26] = 0;
  sub_55071E(Buf);
  v1 = Buf[47];
  if ( *((_BYTE *)Buf + 275) )
  {
    if ( (Buf[24] & 2) == 0 )
      v1 = (v1 + 7) >> 3;
    v2 = Buf[46];
    Buf[48] = v1;
    v3 = (v2 - dword_5F5040[*((unsigned __int8 *)Buf + 276)] + dword_5F505C[*((unsigned __int8 *)Buf + 276)] - 1)
       / (unsigned int)dword_5F505C[*((unsigned __int8 *)Buf + 276)];
    v4 = ((v3 * *((unsigned __int8 *)Buf + 281) + 7) >> 3) + 1;
    Buf[52] = v3;
    Buf[51] = v4;
  }
  else
  {
    v2 = Buf[46];
    Buf[48] = v1;
    v5 = Buf[50] + 1;
    Buf[52] = v2;
    Buf[51] = v5;
  }
  v6 = *((unsigned __int8 *)Buf + 281);
  v7 = Buf[24];
  if ( (v7 & 4) != 0 && *((_BYTE *)Buf + 279) < 8u )
    v6 = 8;
  if ( (v7 & 0x1000) != 0 )
  {
    v8 = *((_BYTE *)Buf + 278);
    if ( v8 == 3 )
    {
      v6 = 8 * (*((_WORD *)Buf + 133) != 0) + 24;
    }
    else if ( v8 )
    {
      if ( v8 == 2 && *((_WORD *)Buf + 133) )
        v6 = 4 * v6 / 3;
    }
    else
    {
      if ( v6 < 8 )
        v6 = 8;
      if ( *((_WORD *)Buf + 133) )
        v6 *= 2;
    }
  }
  if ( (v7 & 0x8000) != 0 )
  {
    v9 = *((_BYTE *)Buf + 278);
    if ( v9 != 3 )
    {
      if ( v9 )
      {
        if ( v9 != 2 )
          goto LABEL_28;
        v10 = v6 > 32 ? 64 : 32;
      }
      else
      {
        v10 = v6 > 8 ? 32 : 16;
      }
      v6 = v10;
      goto LABEL_28;
    }
    v6 = 32;
  }
LABEL_28:
  Buf[55] = (int)sub_554E20(Buf, ((v6 * ((v2 + 7) & 0xFFFFFFF8) + 7) >> 3) + ((v6 + 7) >> 3) + 1);
  v11 = (char *)sub_554E20(Buf, Buf[50] + 1);
  v13 = Buf[50] + 1;
  Buf[54] = (int)v11;
  result = sub_554E92(v7, (int)Buf, v11, 0, v13);
  Buf[23] |= 0x40u;
  return result;
}
