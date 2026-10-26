int sub_5669E0()
{
  int v0; // eax
  int v1; // ebp
  char v2; // cl
  char *v3; // eax
  int v4; // edi
  const char *v5; // eax
  char v6; // bl
  char *v7; // eax
  char *v8; // ebx
  int *v10; // [esp-14h] [ebp-64h]
  int v11; // [esp+Ch] [ebp-44h]
  int v12[7]; // [esp+10h] [ebp-40h] BYREF
  char v13; // [esp+2Fh] [ebp-21h]
  char Buffer[32]; // [esp+30h] [ebp-20h] BYREF

  v0 = *(_DWORD *)dword_B72314;
  v1 = 201;
  if ( *(_DWORD *)dword_B72314 == 8 )
  {
    v2 = byte_91E048;
    if ( byte_91E048 != 2 )
      goto LABEL_11;
    switch ( byte_91E04B )
    {
      case 2:
        v10 = dword_FF3030;
        v3 = sub_41D840(&byte_91CC38, "FAILED");
        break;
      case 3:
        v10 = (int *)&unk_AAAAAA;
        v3 = sub_41D840(&byte_91CC38, "SUCCESS");
        break;
      case 4:
        v10 = dword_FFFF30;
        v3 = sub_41D840(&byte_91CC38, "GOLD");
        break;
      default:
        goto LABEL_11;
    }
    sub_562B70((int)v3, 632, 91, (int)v10, 2, 0, 1.8, 1.8);
    v0 = *(_DWORD *)dword_B72314;
    if ( *(_DWORD *)dword_B72314 == 8 )
    {
      v2 = byte_91E048;
LABEL_11:
      if ( v2 )
      {
        switch ( v2 )
        {
          case 1:
            v4 = 200;
            v11 = 204;
            break;
          case 2:
            v4 = 300;
            v11 = 304;
            break;
          case 3:
            v4 = 100;
            v11 = 103;
            break;
          default:
            v4 = v11;
            break;
        }
      }
      else
      {
        v4 = 100;
        v11 = 103;
      }
      if ( byte_91E04B )
        --v11;
      goto LABEL_30;
    }
  }
  if ( v0 == 7 )
  {
    v4 = 400;
    v11 = 405;
  }
  else
  {
    if ( v0 != 4 )
      goto LABEL_29;
    v5 = Str;
    if ( !Str )
      v5 = WindowName;
    if ( strstr(v5, "Custom") )
    {
      v4 = 500;
      v11 = 506;
    }
    else
    {
LABEL_29:
      v4 = 0;
      v11 = 7;
    }
  }
LABEL_30:
  while ( v4 < v11 )
  {
    v6 = sub_5666C0(Buffer, v4);
    v7 = sub_41D840(&byte_91CC38, Buffer);
    sub_630FE0(v12, v7, 31);
    v13 = 0;
    if ( v4 == dword_B6E4D8 )
      v8 = (char *)(v6 != 0 ? 24960 : 16688384);
    else
      v8 = &byte_FFFFFF[v6 != 0 ? 0xFF808081 : 0];
    sub_562B70((int)v12, 632, v1, (int)v8, 2, 0, 1.5, 1.5);
    v1 += 55;
    ++v4;
  }
  return 0;
}
