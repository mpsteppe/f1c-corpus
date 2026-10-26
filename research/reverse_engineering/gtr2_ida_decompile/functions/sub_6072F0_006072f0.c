int __userpurge sub_6072F0@<eax>(int a1@<ecx>, int a2@<edi>, const char *a3, int a4, int a5, int a6)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  _DWORD *v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int v13; // ebx
  int v14; // edi
  long double v15; // st7
  long double v16; // st6
  double v17; // st7
  float v18; // [esp-18h] [ebp-134h]
  float v19; // [esp+0h] [ebp-11Ch]
  float v20; // [esp+0h] [ebp-11Ch]
  float v21; // [esp+4h] [ebp-118h]
  float v22; // [esp+8h] [ebp-114h]
  char Buffer[256]; // [esp+10h] [ebp-10Ch] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *v24; // [esp+110h] [ebp-Ch]
  void *v25; // [esp+114h] [ebp-8h]
  int v26; // [esp+118h] [ebp-4h]

  v26 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v25 = &loc_6ED07C;
  v24 = ExceptionList;
  sub_606D50((char *)a1, a3);
  if ( a4 == 4 )
  {
    v19 = 1000.0;
    v22 = 2.967236;
    v21 = 2.967236;
    *(_DWORD *)a1 |= 4u;
    v8 = operator new(0x334u);
    a2 = 0;
    v26 = 0;
    if ( v8 )
    {
      a2 = (int)(v8 + 1);
      *v8 = 1;
      sub_630A11(v8 + 1, 816, 1, sub_5E57E0, sub_51D670);
    }
    v26 = -1;
    *(_DWORD *)(a1 + 76) = a2;
    sprintf(Buffer, "REFVIEW");
    sub_5E4F50(*(int **)(a1 + 76), Buffer, a5);
    sub_5E54E0(*(_DWORD *)(a1 + 76), 1065353216, 1148846080);
    sub_4CD350(*(_DWORD **)(a1 + 76), (int)&unk_808080);
    sub_5E5190(*(unsigned int **)(a1 + 76), 1);
    **(_DWORD **)(a1 + 76) &= 0xFFFFFF9F;
  }
  else if ( a4 == 8 )
  {
    *(_DWORD *)a1 |= 8u;
    v9 = 0;
    v19 = 2000.0;
    v22 = 1.5708897;
    v21 = 1.5708897;
    *(_DWORD *)(a1 + 68) = 0;
    v10 = operator new(0x1324u);
    v26 = 1;
    if ( v10 )
    {
      v11 = v10 + 1;
      *v10 = 6;
      sub_630A11(v10 + 1, 816, 6, sub_5E57E0, sub_51D670);
    }
    else
    {
      v11 = 0;
    }
    v26 = -1;
    *(_DWORD *)(a1 + 76) = v11;
    do
    {
      sprintf(Buffer, "REFVIEW%.2d", v9);
      a2 = 816 * v9;
      sub_5E4F50((int *)(816 * v9 + *(_DWORD *)(a1 + 76)), Buffer, a5);
      sub_5E54E0(816 * v9 + *(_DWORD *)(a1 + 76), 1050253722, 1157234688);
      sub_4CD350((_DWORD *)(816 * v9 + *(_DWORD *)(a1 + 76)), (int)&unk_808080);
      sub_5E5190((unsigned int *)(816 * v9 + *(_DWORD *)(a1 + 76)), 1);
      sub_5E4CC0((float *)(816 * v9 + *(_DWORD *)(a1 + 76)), 0.0, 0.0, 0.0);
      *(_DWORD *)(816 * v9 + *(_DWORD *)(a1 + 76)) = *(_DWORD *)(*(_DWORD *)(a1 + 76) + 816 * v9) & 0xFFFFFF9F;
      switch ( v9 )
      {
        case 0:
          v18 = -1.5708897;
          goto LABEL_17;
        case 1:
          v18 = 1.5708897;
          goto LABEL_17;
        case 2:
          sub_5E4D00(a2 + *(_DWORD *)(a1 + 76), 1.5708897, 0.0, 0.0);
          break;
        case 3:
          sub_5E4D00(a2 + *(_DWORD *)(a1 + 76), -1.5708897, 0.0, 0.0);
          break;
        case 4:
          v18 = 0.0;
          goto LABEL_17;
        case 5:
          v18 = 3.1417794;
LABEL_17:
          sub_5E4D00(a2 + *(_DWORD *)(a1 + 76), 0.0, v18, 0.0);
          break;
        default:
          break;
      }
      ++v9;
    }
    while ( v9 < 6 );
  }
  if ( a6 > 0 && sub_606DB0(a1, a2, 0) )
    return -1;
  v13 = 0;
  if ( *(int *)(a1 + 40) > 0 )
  {
    v14 = 0;
    v15 = tan(v22 * 0.5) * v19;
    v16 = tan(v21 * 0.5) * v19;
    v20 = sqrt(v16 * v16 + v15 * v15);
    do
    {
      sub_5E5240(v14 + *(_DWORD *)(a1 + 76), SLODWORD(v22), v21, 0);
      if ( *(float *)(a1 + 68) <= (double)v20 )
        v17 = v20;
      else
        v17 = *(float *)(a1 + 68);
      *(float *)(a1 + 68) = v17;
      ++v13;
      v14 += 816;
    }
    while ( v13 < *(_DWORD *)(a1 + 40) );
  }
  return 0;
}
