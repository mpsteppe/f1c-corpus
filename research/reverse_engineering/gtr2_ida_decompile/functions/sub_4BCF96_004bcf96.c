double __stdcall sub_4BCF96(char a1)
{
  int v1; // esi
  char *v2; // eax
  _DWORD *v3; // eax
  char *v4; // eax
  int v5; // edx
  _DWORD *v6; // eax
  char *v7; // eax
  float v9; // [esp+0h] [ebp-110h]
  float v10; // [esp+4h] [ebp-10Ch] BYREF
  int v11; // [esp+8h] [ebp-108h] BYREF
  int v12; // [esp+Ch] [ebp-104h] BYREF
  char String1[256]; // [esp+10h] [ebp-100h] BYREF

  v1 = 0;
  v9 = -1.0;
  if ( a1 )
  {
    switch ( *(_DWORD *)dword_B72314 )
    {
      case 2:
        v1 = 6;
        break;
      case 3:
        if ( byte_B6FEBC == 1 )
        {
          v1 = 1;
        }
        else if ( byte_B6FED4 == 1 )
        {
          v1 = 2;
        }
        else if ( byte_B6FEEC == 1 )
        {
          v1 = 3;
        }
        else if ( byte_B6FF04 == 1 )
        {
          v1 = 4;
        }
        else
        {
          v1 = (byte_B6FF1C != 1) + 5;
        }
        break;
      case 4:
        v1 = *(_DWORD *)dword_B640C8;
        break;
    }
    if ( (unsigned __int8)sub_4735A0() && sub_473630(&dword_B6CBA8) )
      v1 = 1;
    sub_430F70(&dword_B640C0, v1);
  }
  else
  {
    v1 = *(_DWORD *)dword_B640C8;
  }
  if ( *(_DWORD *)dword_B72314 == 5 )
    v1 = 1;
  v2 = sub_42FEC0(v1, 0, 1);
  sub_632041(String1, 256, "%sStart", v2);
  if ( sub_53A250(0) )
  {
    v3 = (_DWORD *)sub_616630(String1);
    if ( v3 )
    {
      v10 = 0.0;
      v4 = sub_48D380(v3);
      if ( sscanf(v4, "%d:%d:%f", &v11, &v12, &v10) >= 2 )
        v9 = (double)v11 * 3600.0 + (double)v12 * 60.0 + v10;
    }
  }
  if ( sub_616840("SceneOrder")
    && (v5 = dword_BE1CD8 + 396 * dword_BE1CD4) != 0
    && sub_616630((char *)(v5 + 260))
    && (v6 = (_DWORD *)sub_616630(String1)) != 0
    && (v10 = 0.0, v7 = sub_48D380(v6), sscanf(v7, "%d:%d:%f", &v12, &v11, &v10) >= 2) )
  {
    return (double)v12 * 3600.0 + (double)v11 * 60.0 + v10;
  }
  else
  {
    return v9;
  }
}
