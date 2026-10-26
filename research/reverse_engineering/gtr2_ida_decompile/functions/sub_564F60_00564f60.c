int __stdcall sub_564F60(int a1, float a2, float a3)
{
  int result; // eax
  unsigned int v4; // eax
  int v5; // edi
  int v6; // [esp+18h] [ebp-8Ch] BYREF
  int v7; // [esp+1Ch] [ebp-88h] BYREF
  float v8; // [esp+20h] [ebp-84h]
  char Buffer[127]; // [esp+24h] [ebp-80h] BYREF
  char v10; // [esp+A3h] [ebp-1h]
  float v11; // [esp+B0h] [ebp+Ch]

  result = 1;
  if ( a1 )
  {
    v4 = *(_DWORD *)(a1 + 19324) - 1;
    if ( v4 <= 0x18 )
    {
      sprintf(Buffer, "%c", (char)(v4 + byte_903BA0));
      sub_562B70((int)Buffer, (unsigned __int64)a2, (unsigned __int64)a3, (int)byte_FFFFFF, 0, 7, 3.0, 3.0);
    }
    sub_630FE0(Buffer, 108 * *(_DWORD *)(a1 + 21788) + a1 + 21656, 127);
    v10 = 0;
    _strupr(Buffer);
    v5 = (unsigned __int64)(a2 + 110.0);
    sub_562B70((int)Buffer, v5, (unsigned __int64)a3, (int)byte_FFFFFF, 0, 0, 1.0, 1.0);
    sub_630FE0(Buffer, a1 + 21872, 127);
    v10 = 0;
    _strupr(Buffer);
    v11 = a3 + 40.0;
    sub_562B70((int)Buffer, v5, (unsigned __int64)v11, (int)&loc_48AAB3, 0, 0, 1.0, 1.0);
    v8 = *(float *)(a1 + 19320);
    if ( v8 >= 0.0 )
    {
      v7 = 0;
      *(float *)&v6 = 0.0;
      sub_4E42B0(v8, &v7, (float *)&v6);
      sprintf(Buffer, "%.2d:%06.3f", v7, *(float *)&v6);
    }
    else
    {
      sub_630FE0(Buffer, &dword_713280, 127);
      v10 = 0;
    }
    sub_562B70((int)Buffer, v5, (unsigned __int64)(v11 + 40.0), (int)dword_FFFF00, 0, 0, 1.0, 1.0);
    return 0;
  }
  return result;
}
