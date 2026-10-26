int __thiscall sub_65DF43(_DWORD *this, int a2, double *a3)
{
  _DWORD *v5; // [esp+4h] [ebp-10Ch]
  char ArgList[256]; // [esp+10h] [ebp-100h] BYREF

  switch ( *(_DWORD *)a3 )
  {
    case 0:
      sub_632041((int)ArgList, 256, "version token");
      break;
    case 1:
      v5 = a3 + 1;
      goto LABEL_13;
    case 2:
      sub_632041((int)ArgList, 256, "integer '%u'", *((_DWORD *)a3 + 2));
      break;
    case 3:
      sub_632041((int)ArgList, 256, "integer '%dl'", *((_DWORD *)a3 + 2));
      break;
    case 4:
      sub_632041((int)ArgList, 256, "integer '%uul'", *((_DWORD *)a3 + 2));
      break;
    case 5:
      sub_632041((int)ArgList, 256, "float '%g'", a3[1]);
      break;
    case 6:
      sub_632041((int)ArgList, 256, "float '%gh'", a3[1]);
      break;
    case 7:
      sub_632041((int)ArgList, 256, "float '%gf'", a3[1]);
      break;
    case 8:
      sub_632041((int)ArgList, 256, "float '%gl'", a3[1]);
      break;
    case 9:
      v5 = (_DWORD *)*((_DWORD *)a3 + 2);
LABEL_13:
      sub_632041((int)ArgList, 256, "token '%s'", v5);
      break;
    case 0xA:
      sub_632041((int)ArgList, 256, "string constant");
      break;
    case 0xC:
      sub_632041((int)ArgList, 256, "end of line");
      break;
    case 0xD:
      sub_632041((int)ArgList, 256, "end of file");
      break;
    default:
      sub_632041((int)ArgList, 256, "token");
      break;
  }
  return sub_65DD1F(this, (int)a3, a2, "syntax error : unexpected %s", ArgList);
}
