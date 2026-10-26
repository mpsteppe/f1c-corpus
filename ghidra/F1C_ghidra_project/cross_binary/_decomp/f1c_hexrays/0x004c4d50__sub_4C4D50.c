// f1c  0x004c4d50  size=668
int __thiscall sub_4C4D50(_DWORD *this, const char *a2)
{
  int v2; // ebx
  int i; // esi
  int *v5; // eax
  _DWORD *v6; // ecx
  int v7; // ebx
  int v8; // edi
  int *v9; // esi
  int v10; // eax
  int v11; // edx
  int result; // eax
  int v13; // [esp+10h] [ebp-384h] BYREF
  int v14; // [esp+14h] [ebp-380h]
  int v15; // [esp+18h] [ebp-37Ch] BYREF
  int v16; // [esp+1Ch] [ebp-378h] BYREF
  char v17[8]; // [esp+20h] [ebp-374h] BYREF
  char v18[8]; // [esp+28h] [ebp-36Ch] BYREF
  char v19[8]; // [esp+30h] [ebp-364h] BYREF
  int v20; // [esp+38h] [ebp-35Ch] BYREF
  _DWORD v21[50]; // [esp+3Ch] [ebp-358h] BYREF
  _DWORD v22[50]; // [esp+104h] [ebp-290h] BYREF
  _DWORD v23[50]; // [esp+1CCh] [ebp-1C8h] BYREF
  char v24[256]; // [esp+294h] [ebp-100h] BYREF

  v2 = 0;
  v13 = 0;
  sub_4C4CF0(this);
  if ( !a2 || !strcmp(a2, byte_5EA438) || dword_7D0398 && dword_7D0410 != 5 )
  {
    sub_566650(byte_5EA438);
    v7 = dword_8AC390;
    v8 = 0;
    if ( dword_8AC390 > 0 )
    {
      v13 = dword_8AC390;
      do
      {
        v9 = (int *)sub_587C03(4);
        *v9 = v8;
        v10 = sub_587C03(12);
        if ( v10 )
        {
          *(_DWORD *)v10 = v9;
          *(_DWORD *)(v10 + 4) = 0;
          *(_BYTE *)(v10 + 8) = 1;
        }
        else
        {
          v10 = 0;
        }
        if ( this[2] )
        {
          *(_DWORD *)(this[3] + 4) = v10;
        }
        else
        {
          this[2] = v10;
          this[4] = v10;
        }
        v11 = this[5] + 1;
        ++v8;
        this[3] = v10;
        this[5] = v11;
      }
      while ( v8 < v7 );
    }
  }
  else
  {
    sub_566650(a2);
    strcpy(v18, "AND:");
    strcpy(v17, " ,\t\n");
    strcpy(v19, "NOT:");
    v20 = dword_5D30C0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    strcpy(v24, a2);
    memset(v22, 0, sizeof(v22));
    memset(v21, 0, sizeof(v21));
    for ( i = sub_5897CA(v24, v17); i; i = sub_5897CA(0, v17) )
    {
      if ( sub_588410(i, v18) )
      {
        if ( sub_588410(i, &v20) )
        {
          if ( sub_588410(i, v19) )
          {
            switch ( v14 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                v5 = &v16;
                v6 = &v22[v16];
                break;
              case 2:
                v5 = &v13;
                v6 = &v23[v13];
                break;
              default:
LABEL_17:
                v5 = &v15;
                v6 = &v21[v2];
                break;
            }
            if ( *v5 < 49 )
            {
              ++*v5;
              v2 = v15;
              *v6 = i;
            }
            continue;
          }
          v14 = 2;
        }
        else
        {
          v14 = 1;
        }
      }
      else
      {
        v14 = 0;
      }
    }
    sub_4C4990(this, v21, v2);
    sub_4C4AA0(this, v22, v16);
    v13 = sub_4C4BB0(this, v23, v13);
  }
  this[4] = this[2];
  result = v13;
  this[6] = 0;
  return result;
}
