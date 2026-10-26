int __thiscall sub_4DCC40(_DWORD *this, const char *a2)
{
  float *v3; // eax
  float *v4; // esi
  _DWORD *v5; // edi
  int v6; // eax
  int v8; // [esp+Ch] [ebp-9Ch] BYREF
  int v9; // [esp+10h] [ebp-98h] BYREF
  int v10; // [esp+14h] [ebp-94h] BYREF
  int v11; // [esp+18h] [ebp-90h] BYREF
  _DWORD *v12; // [esp+1Ch] [ebp-8Ch]
  int v13; // [esp+20h] [ebp-88h] BYREF
  int v14; // [esp+24h] [ebp-84h] BYREF
  int v15[32]; // [esp+28h] [ebp-80h] BYREF

  memset(v15, 0, sizeof(v15));
  v12 = this;
  if ( a2 && strlen(a2) && !sub_4DEDE0(this[194], a2) )
  {
    v3 = (float *)operator new(0x20u);
    if ( v3 )
    {
      v3[1] = NAN;
      *v3 = 0.0;
      v3[3] = NAN;
      v3[2] = 0.0;
      v3[5] = NAN;
      v3[4] = 0.0;
      v3[6] = 1.0;
      v3[7] = 1.0;
      v4 = v3;
    }
    else
    {
      v4 = 0;
    }
    sub_615860(a2);
    v5 = v12;
    while ( sub_4DAC90(v5) )
    {
      if ( strstr(byte_75AF70, "}") )
        break;
      if ( sub_6131C0("FILE", (int)v15) )
      {
        sub_615860(v15);
      }
      else if ( sub_6133A0("COLORARGB", (int)&v10, (int)&v14, (int)&v8, (int)&v9) )
      {
        *((_DWORD *)v4 + 5) = v9 | ((v8 | ((v14 | (v10 << 8)) << 8)) << 8);
      }
      else if ( sub_6134B0("SCALE", (int)&v13, (int)&v11, 0, 0, 0, 0, 0, 0) )
      {
        v6 = v13;
        v4[7] = *(float *)&v11;
        *((_DWORD *)v4 + 6) = v6;
      }
    }
    if ( (unsigned __int8)sub_4E37E0(v4) )
    {
      sub_5FDFB0(v4, 1);
      return 0;
    }
    if ( v4 )
    {
      if ( *((_DWORD *)v4 + 2) )
        j_j__free(*((void **)v4 + 2));
      if ( *(_DWORD *)v4 )
        j_j__free(*(void **)v4);
      j__free(v4);
    }
  }
  return -1;
}
