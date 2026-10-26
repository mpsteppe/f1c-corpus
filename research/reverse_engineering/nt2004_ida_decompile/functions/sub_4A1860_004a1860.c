int __thiscall sub_4A1860(void *this, int a2, int a3)
{
  int v5; // eax
  int v6; // edi
  UINT v7; // eax
  char *v8; // edx
  int v9; // eax
  unsigned __int8 v10; // bl
  _BYTE *v11; // ecx
  int v12; // eax
  char *v13; // eax
  int v14; // eax
  int v15; // [esp+4h] [ebp-14h]
  int v16; // [esp+Ch] [ebp-Ch] BYREF
  int v17; // [esp+10h] [ebp-8h] BYREF
  int v18; // [esp+14h] [ebp-4h] BYREF

  if ( !*((_BYTE *)this + 792) )
    return 0;
  v5 = 0;
  v6 = 0;
  v15 = 0;
  if ( a3 > 0 )
  {
    while ( 2 )
    {
      v7 = *(unsigned __int16 *)(a2 + 2 * v5);
      switch ( v7 )
      {
        case 1u:
          v8 = (char *)*((_DWORD *)this + 199);
          if ( v8 )
            strcpy(v8, &byte_629120);
          goto LABEL_7;
        case 0xEu:
          v9 = *((_DWORD *)this + 200);
          if ( v9 != *((_DWORD *)this + 199) )
            *((_DWORD *)this + 200) = v9 - 1;
          **((_BYTE **)this + 200) = 0;
          goto LABEL_24;
        case 0x1Cu:
LABEL_7:
          if ( !*((_BYTE *)this + 273) )
          {
            sub_4A1BB0(0);
            sub_4AD850(0);
          }
          (*(void (__thiscall **)(void *))(*(_DWORD *)this + 168))(this);
          goto LABEL_24;
        case 0x37u:
        case 0x4Au:
        case 0x4Eu:
          goto LABEL_25;
        default:
          v10 = sub_458220(v7);
          if ( !sub_4A17C0((int)this, v10) )
            goto LABEL_25;
          if ( *((_DWORD *)this + 200) - *((_DWORD *)this + 199) < *((_DWORD *)this + 201) )
          {
            **((_BYTE **)this + 200) = v10;
            v11 = (_BYTE *)(*((_DWORD *)this + 200) + 1);
            *((_DWORD *)this + 200) = v11;
            *v11 = 0;
            if ( *((_DWORD *)this + 202) )
            {
              v12 = *((_DWORD *)this + 61);
              if ( v12 )
              {
                if ( *((_DWORD *)this + 12) )
                {
                  v13 = *(char **)(v12 + 64);
                  if ( !v13 )
                    v13 = &byte_629120;
                  sub_4AE350(v13);
                  sub_4AE230(*((char **)this + 202), (int)&v18, (int)&v16);
                  sub_4AE230(*((char **)this + 199), (int)&v17, (int)&v16);
                  if ( v17 > v18 )
                  {
                    v14 = *((_DWORD *)this + 200);
                    if ( v14 != *((_DWORD *)this + 199) )
                      *((_DWORD *)this + 200) = v14 - 1;
                    **((_BYTE **)this + 200) = 0;
                  }
                }
              }
            }
          }
LABEL_24:
          v6 = 1;
LABEL_25:
          v5 = ++v15;
          if ( v15 >= a3 )
            return v6;
          continue;
      }
    }
  }
  return v6;
}
