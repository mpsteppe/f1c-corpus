int __thiscall sub_4BCED0(int this, char *a2, char *a3, const char *a4)
{
  int result; // eax
  char v6[253]; // [esp+10h] [ebp-100h] BYREF
  __int16 v7; // [esp+10Dh] [ebp-3h]
  char v8; // [esp+10Fh] [ebp-1h]

  v6[0] = byte_629120;
  memset(&v6[1], 0, 0xFCu);
  v7 = 0;
  v8 = 0;
  strcpy(v6, a4);
  v6[2] = 0;
  *a3 = 0;
  if ( strcmp(a2, aLfwheeloffMts) )
  {
    if ( !strcmp(a2, aLfwheelonMts) )
    {
      sub_4BCDE0(v6, (const char *)&off_609DB0);
      sub_4BCDE0(a3, (const char *)&off_609DB0);
      *(_DWORD *)(this + 72) = 0;
    }
    else
    {
      if ( !strcmp(a2, aRfwheeloffMts) )
      {
        sub_4BCDE0(v6, (const char *)&off_609DB0);
        sub_4BCDE0(a3, (const char *)&off_609DB0);
        *(_BYTE *)(this + 2) = 0;
        *(_DWORD *)(this + 72) = 1;
        goto LABEL_18;
      }
      if ( !strcmp(a2, aRfwheelonMts) )
      {
        sub_4BCDE0(v6, (const char *)&off_609DB0);
        sub_4BCDE0(a3, (const char *)&off_609DB0);
        *(_BYTE *)(this + 2) = 1;
        *(_DWORD *)(this + 72) = 1;
        goto LABEL_18;
      }
      if ( !strcmp(a2, aLrwheeloffMts) )
      {
        sub_4BCDE0(v6, (const char *)&off_609D6C);
        sub_4BCDE0(a3, (const char *)&off_609D6C);
        *(_BYTE *)(this + 2) = 0;
        *(_DWORD *)(this + 72) = 2;
        goto LABEL_18;
      }
      if ( !strcmp(a2, aLrwheelonMts) )
      {
        sub_4BCDE0(v6, (const char *)&off_609D6C);
        sub_4BCDE0(a3, (const char *)&off_609D6C);
        *(_DWORD *)(this + 72) = 2;
      }
      else
      {
        if ( !strcmp(a2, aRrwheeloffMts) )
        {
          sub_4BCDE0(v6, (const char *)&off_609D6C);
          sub_4BCDE0(a3, (const char *)&off_609D6C);
          *(_BYTE *)(this + 2) = 0;
          *(_DWORD *)(this + 72) = 3;
          goto LABEL_18;
        }
        if ( strcmp(a2, aRrwheelonMts) )
          goto LABEL_18;
        sub_4BCDE0(v6, (const char *)&off_609D6C);
        sub_4BCDE0(a3, (const char *)&off_609D6C);
        *(_DWORD *)(this + 72) = 3;
      }
    }
    *(_BYTE *)(this + 2) = 1;
    goto LABEL_18;
  }
  sub_4BCDE0(v6, (const char *)&off_609DB0);
  sub_4BCDE0(a3, (const char *)&off_609DB0);
  *(_BYTE *)(this + 2) = 0;
  *(_DWORD *)(this + 72) = 0;
LABEL_18:
  strcpy(a2, v6);
  return result;
}
