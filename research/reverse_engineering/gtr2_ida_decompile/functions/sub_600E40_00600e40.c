int __thiscall sub_600E40(int *this, _DWORD *a2, const char *a3, int a4, char a5)
{
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  int *v8; // eax
  int *v9; // ebp
  int v10; // eax
  _DWORD *v11; // ecx
  unsigned int *v12; // eax
  unsigned int v13; // edx

  v6 = operator new(0xE8u);
  v7 = 0;
  if ( v6 )
    v7 = sub_600800(v6);
  sub_600600((int)v7, a3, a4);
  v7[57] = this;
  switch ( a4 )
  {
    case 2:
      v8 = (int *)this[188];
      v9 = this + 188;
      this[190] = (int)v8;
      if ( v8 )
        v10 = *v8;
      else
        v10 = 0;
      if ( !strcmp((const char *)(v10 + 4), "DefaultDirLight") )
        sub_5DB730(v9, v10, 1);
      sub_5FDFB0(v9, (int)v7, 1);
      break;
    case 3:
      v11 = this + 193;
      goto LABEL_13;
    case 4:
      v11 = this + 203;
      goto LABEL_13;
    case 5:
      v11 = this + 198;
LABEL_13:
      sub_5FDFB0(v11, (int)v7, 1);
      break;
    default:
      break;
  }
  if ( (a5 & 1) != 0 && (*v7 & 1) == 0 )
  {
    *v7 |= 1u;
    switch ( v7[5] )
    {
      case 2:
        ++*(_DWORD *)(v7[57] + 748);
        break;
      case 3:
        ++*(_DWORD *)(v7[57] + 768);
        v12 = (unsigned int *)v7[57];
        v13 = (unsigned int)&dword_1000000 | *v12;
        goto LABEL_21;
      case 4:
        ++*(_DWORD *)(v7[57] + 808);
        break;
      case 5:
        ++*(_DWORD *)(v7[57] + 788);
        v12 = (unsigned int *)v7[57];
        v13 = (unsigned int)&dword_2000000 | *v12;
LABEL_21:
        *v12 = v13;
        break;
      default:
        break;
    }
  }
  if ( (a5 & 2) != 0 )
    *v7 |= 2u;
  if ( a2 )
    *a2 = v7;
  return 0;
}
