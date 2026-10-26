int __userpurge sub_606DB0@<eax>(int a1@<ecx>, char a2@<dil>, char a3)
{
  int v5; // ebp
  _DWORD *v6; // eax
  char *v7; // edi
  char *v8; // ecx
  char *v9; // eax
  char *v10; // edi
  int i; // edi
  int v12; // [esp-20h] [ebp-74h]
  char v14; // [esp+0h] [ebp-54h]
  char Buffer[64]; // [esp+8h] [ebp-4Ch] BYREF
  int v16; // [esp+50h] [ebp-4h]

  if ( !*(_DWORD *)(a1 + 76) )
  {
    sub_5D8C80(a1, (char *)0xFFFFFFFF, "No cubeView allocated - no use for a texture.", v14);
    return -1;
  }
  if ( (*(_BYTE *)a1 & 0x40) != 0 )
    return 0;
  if ( !a3 )
  {
    v5 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 292))(dword_FB27A4, 1);
    sprintf(Buffer, "RMAP%.3dTEX", *(_DWORD *)(a1 + 36));
    v6 = operator new(0xDCu);
    v16 = 0;
    if ( v6 )
    {
      v7 = (char *)(v6 + 1);
      *v6 = 1;
      sub_630A11(v6 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    v12 = *(_DWORD *)(a1 + 44);
    v16 = -1;
    *(_DWORD *)(a1 + 80) = v8;
    if ( sub_5E2E70(v8, Buffer, v12, v12, v5, 1, 88, 32770) )
      goto LABEL_11;
    sub_5E6F50(*(_DWORD **)(a1 + 80), 0, 0, *(_DWORD *)(a1 + 44), *(_DWORD *)(a1 + 44), 0);
    sub_5FDFB0(&dword_FB2D78, *(_DWORD *)(a1 + 80), 0);
    goto LABEL_15;
  }
  if ( !sub_5E2E70(
          *(char **)(a1 + 80),
          (const char *)(*(_DWORD *)(a1 + 80) + 140),
          *(_DWORD *)(a1 + 44),
          *(_DWORD *)(a1 + 44),
          *(_DWORD *)(*(_DWORD *)(a1 + 80) + 24),
          1,
          88,
          32770) )
  {
LABEL_15:
    if ( (*(_DWORD *)a1 & 8) != 0 )
    {
      for ( i = 0; i < 6; ++i )
      {
        switch ( i )
        {
          case 0:
            sub_5E55E0(*(_DWORD **)(a1 + 76), *(_DWORD *)(a1 + 80));
            *(_DWORD *)(*(_DWORD *)(a1 + 76) + 776) = 0;
            break;
          case 1:
            sub_5E55E0((_DWORD *)(*(_DWORD *)(a1 + 76) + 816), *(_DWORD *)(a1 + 80));
            *(_DWORD *)(*(_DWORD *)(a1 + 76) + 1592) = 1;
            break;
          case 2:
            sub_5E55E0((_DWORD *)(*(_DWORD *)(a1 + 76) + 1632), *(_DWORD *)(a1 + 80));
            *(_DWORD *)(*(_DWORD *)(a1 + 76) + 2408) = 2;
            break;
          case 3:
            sub_5E55E0((_DWORD *)(*(_DWORD *)(a1 + 76) + 2448), *(_DWORD *)(a1 + 80));
            *(_DWORD *)(*(_DWORD *)(a1 + 76) + 3224) = 3;
            break;
          case 4:
            sub_5E55E0((_DWORD *)(*(_DWORD *)(a1 + 76) + 3264), *(_DWORD *)(a1 + 80));
            *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4040) = 4;
            break;
          case 5:
            sub_5E55E0((_DWORD *)(*(_DWORD *)(a1 + 76) + 4080), *(_DWORD *)(a1 + 80));
            *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4856) = 5;
            break;
          default:
            continue;
        }
      }
    }
    else if ( (*(_DWORD *)a1 & 4) != 0 )
    {
      sub_5E55E0(*(_DWORD **)(a1 + 76), *(_DWORD *)(a1 + 80));
    }
    *(_DWORD *)a1 |= 0x40u;
    return 0;
  }
LABEL_11:
  v9 = *(char **)(a1 + 80);
  if ( v9 )
  {
    v10 = v9 - 4;
    `eh vector destructor iterator'(v9, 0xD8u, *((_DWORD *)v9 - 1), j_j_nullsub_7);
    j__free(v10);
  }
  *(_DWORD *)(a1 + 80) = 0;
  sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error allocating reflection mapper target surface", a2);
  return -1;
}
