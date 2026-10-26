int __thiscall sub_502350(_DWORD *this)
{
  const char *v2; // eax
  int v3; // ebp
  char *v4; // edx
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v9; // [esp+Ch] [ebp-CCh] BYREF
  int v10; // [esp+10h] [ebp-C8h] BYREF
  int v11; // [esp+14h] [ebp-C4h]
  char v12[32]; // [esp+18h] [ebp-C0h] BYREF
  char v13[32]; // [esp+38h] [ebp-A0h] BYREF
  char Buffer[128]; // [esp+58h] [ebp-80h] BYREF

  sub_502730(this);
  v2 = (const char *)dword_62A098;
  v10 = 0;
  if ( !dword_62A098 )
    v2 = &byte_629120;
  sprintf(Buffer, "%s%s", v2, off_612B48);
  sub_5924D0(dword_7DA988, (int)&v10, (int)Buffer);
  if ( v10 )
  {
    v3 = 0;
    while ( 1 )
    {
      v9 = 0;
      if ( !v3 )
        break;
      switch ( v3 )
      {
        case 1:
          sprintf(v12, "%s", off_612B38[0]);
          sprintf(v13, "%s%s", off_612B38[0], off_612B44[0]);
          break;
        case 2:
          sprintf(v12, "%s", off_612B3C[0]);
          sprintf(v13, "%s%s", off_612B3C[0], off_612B44[0]);
          break;
        case 3:
          sprintf(v12, "%s", off_612B40[0]);
          v4 = off_612B40[0];
          goto LABEL_13;
      }
LABEL_14:
      v11 = sub_592A60(&v9, v13, 133120);
      if ( v9 )
      {
        sub_5A3F40(0, 192);
        sub_5A3F60(0, 0);
        *(_DWORD *)(v9 + 172) = this[22];
        *(_DWORD *)(v9 + 176) = this[23];
        v5 = operator new(8u);
        v6 = v5;
        if ( v5 )
        {
          *v5 = 0;
          v5[1] = -1;
          sub_578600(v12);
          v7 = operator new(0xCu);
          if ( v7 )
          {
            *v7 = v6;
            v7[1] = 0;
            *((_BYTE *)v7 + 8) = 1;
          }
          else
          {
            v7 = 0;
          }
          if ( *this )
          {
            *(_DWORD *)(this[1] + 4) = v7;
          }
          else
          {
            *this = v7;
            this[2] = v7;
          }
          this[1] = v7;
          ++this[3];
        }
      }
      if ( ++v3 >= 4 )
      {
        sub_592750(v10);
        return v11;
      }
    }
    sprintf(v12, "%s", off_612B34[0]);
    v4 = off_612B34[0];
LABEL_13:
    sprintf(v13, "%s%s", v4, off_612B44[0]);
    goto LABEL_14;
  }
  return 1;
}
