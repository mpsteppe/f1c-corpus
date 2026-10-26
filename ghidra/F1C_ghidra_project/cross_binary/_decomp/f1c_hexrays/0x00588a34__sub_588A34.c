// f1c  0x00588a34  size=582
int __cdecl sub_588A34(unsigned int a1, _BYTE *a2)
{
  char *v2; // ebx
  int v3; // eax
  int v4; // esi
  _BYTE *v5; // edi
  _BYTE *i; // esi
  int v7; // eax
  char **v8; // ebx
  int v9; // eax
  char *v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // edi
  char *v13; // edi
  bool v14; // zf
  LPVOID *v15; // edi
  _BYTE v17[132]; // [esp+8h] [ebp-88h] BYREF
  int v18; // [esp+8Ch] [ebp-4h]
  int v19; // [esp+98h] [ebp+8h]
  int v20; // [esp+9Ch] [ebp+Ch]

  v2 = 0;
  if ( a1 <= 5 )
  {
    sub_58DFEA(19);
    ++dword_8D5A58;
    while ( dword_8D5A5C )
      Sleep(1u);
    if ( a1 )
    {
      if ( a2 )
      {
        v3 = sub_588C7A((LPVOID)a1, a2);
LABEL_45:
        v4 = v3;
        goto LABEL_46;
      }
      v4 = (int)*(&dword_5E64F4 + 3 * a1);
LABEL_46:
      sub_58E04B(19);
LABEL_47:
      --dword_8D5A58;
      return v4;
    }
    v5 = a2;
    v18 = 1;
    v19 = 0;
    if ( a2 )
    {
      if ( *a2 == 76 && a2[1] == 67 && a2[2] == 95 )
      {
        for ( i = (_BYTE *)sub_58FC60(a2, "=;"); i; i = (_BYTE *)sub_58FC60(v5, "=;") )
        {
          v7 = i - v5;
          v18 = i - v5;
          if ( i == v5 || *i == 59 )
            break;
          v20 = 1;
          v8 = &off_5E64FC;
          while ( 1 )
          {
            if ( !sub_588640(*v8, v5, v7) )
            {
              v9 = sub_58E1B0(*v8);
              if ( v18 == v9 )
                break;
            }
            ++v20;
            v8 += 3;
            if ( (int)v8 > (int)&off_5E652C )
              break;
            v7 = v18;
          }
          v10 = i + 1;
          v11 = sub_58FC20(v10, ";");
          v12 = v11;
          if ( !v11 && *v10 != 59 )
            break;
          if ( v20 <= 5 )
          {
            sub_587DD0(v17, v10, v11);
            v17[v12] = 0;
            if ( sub_588C7A((LPVOID)v20, v17) )
              ++v19;
          }
          v13 = &v10[v12];
          if ( *v13 )
          {
            v5 = v13 + 1;
            if ( *v5 )
              continue;
          }
          v14 = v19 == 0;
          goto LABEL_31;
        }
        sub_58E04B(19);
        v4 = 0;
        goto LABEL_47;
      }
      v4 = sub_588E4E(a2, v17, 0, 0);
      if ( !v4 )
        goto LABEL_46;
      v15 = &dword_5E64F4;
      do
      {
        if ( v15 != &dword_5E64F4 )
        {
          if ( !sub_58FB90(v17, *v15) || sub_588C7A(v2, v17) )
            ++v19;
          else
            v18 = 0;
        }
        v15 += 3;
        ++v2;
      }
      while ( (int)v15 <= (int)&off_5E6530 );
      if ( v18 )
      {
        v4 = sub_588D95();
        sub_58AA6F(dword_5E64F4);
        dword_5E64F4 = 0;
        goto LABEL_46;
      }
      v14 = v19 == 0;
LABEL_31:
      if ( v14 )
      {
        v4 = 0;
        goto LABEL_46;
      }
    }
    v3 = sub_588D95();
    goto LABEL_45;
  }
  return 0;
}
