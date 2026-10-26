int __thiscall sub_612A40(char *this, int *a2, char *a3, int a4, _DWORD *a5, _DWORD *a6, int a7)
{
  char *v7; // edx
  int *v8; // eax
  bool v9; // zf
  int v11; // ebx
  int v12; // ecx
  int v13; // eax
  int v15; // eax
  char *v16; // eax
  char v17; // [esp+0h] [ebp-10h]

  v7 = a3;
  v8 = (int *)*a2;
  v9 = *a2 == 0;
  v11 = (int)a3;
  a2[2] = *a2;
  if ( v9 )
    v12 = 0;
  else
    v12 = *v8;
  a3 = (char *)v12;
  if ( v12 )
  {
    v11 = a4;
    if ( a4 <= (int)v7 )
    {
      v15 = *(_DWORD *)(v12 + 8);
      if ( a4 > *(_DWORD *)(v12 + 4) - v15 )
      {
        sub_60B970((char *)v12, 0x2000, 0, 0);
        *((_DWORD *)a3 + 2) = 0;
      }
      else
      {
        sub_60B970((char *)v12, 4096, v15, a4);
      }
      goto LABEL_15;
    }
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)this + 448))(this, v12);
    sub_59F730(a2, (int)a3, 1);
    a3 = 0;
  }
  v13 = 262146;
  if ( this[4] < 0 )
    v13 = 262210;
  if ( (*(int (__thiscall **)(char *, char **, int, int))(*(_DWORD *)this + 444))(this, &a3, v11, v13) )
  {
    sub_5D8C80((int)(this + 4), (char *)0xFFFFFFFF, "Error creating new dynamic index buffer", v17);
    return -1;
  }
  sub_5FDFB0(a2, (int)a3, 0);
  sub_60B970(a3, 0x2000, 0, 0);
  v11 = a4;
  *((_DWORD *)a3 + 2) = 0;
LABEL_15:
  v16 = a3;
  if ( a5 )
    *a5 = a3;
  if ( a6 )
    *a6 = *((_DWORD *)v16 + 2);
  *((_DWORD *)v16 + 2) += v11;
  return 0;
}
