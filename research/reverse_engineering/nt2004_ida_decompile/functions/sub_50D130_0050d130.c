char __thiscall sub_50D130(_DWORD *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  char *v5; // eax
  char v7; // [esp+Fh] [ebp-A09h]
  char Buffer[8]; // [esp+10h] [ebp-A08h] BYREF
  char String[512]; // [esp+18h] [ebp-A00h] BYREF
  char v10[512]; // [esp+218h] [ebp-800h] BYREF
  char v11[512]; // [esp+418h] [ebp-600h] BYREF
  char v12[512]; // [esp+618h] [ebp-400h] BYREF
  char v13[512]; // [esp+818h] [ebp-200h] BYREF

  v2 = dword_7D6A5C + 1232 * *(_DWORD *)(*this + 25252);
  LOBYTE(v3) = this[38] != 0;
  v7 = v3;
  if ( v2 || this[38] )
  {
    if ( (v3 = sub_4E6CD0((char *)v2), v3 > 0) && this[37] < v3 || v7 )
    {
      v4 = *this;
      String[0] = 0;
      v10[0] = 0;
      v12[0] = 0;
      v11[0] = 0;
      v13[0] = 0;
      sprintf(Buffer, "_%02d", *(_DWORD *)(v4 + 25248));
      sub_405480(String, 0x1FFu, "%s", (const char *)(v2 + 1164));
      v5 = &String[strlen(String)];
      if ( v5 > String )
      {
        while ( *v5 != 46 )
        {
          if ( --v5 <= String )
            goto LABEL_11;
        }
        *v5 = 0;
      }
LABEL_11:
      strcat(String, Buffer);
      sub_405480(v10, 0x1FFu, Format, String, &off_613158);
      sub_405480(v12, 0x1FFu, "%s%s", String, aDriver_0);
      sub_405480(v11, 0x1FFu, "%s%s", String, aDriverArm);
      sub_405480(v13, 0x1FFu, "%s%s", String, aDriverhelm);
      _strupr(String);
      sub_505E40((int)aWccarbody, (int)String);
      _strupr(v10);
      sub_505E40((int)aWcrims, (int)v10);
      _strupr(v12);
      sub_505E40((int)aWccardriver, (int)v12);
      _strupr(v11);
      sub_505E40((int)aWcDriverArm, (int)v11);
      _strupr(v13);
      LOBYTE(v3) = sub_505E40((int)aWcdriverhelm, (int)v13);
    }
  }
  return v3;
}
