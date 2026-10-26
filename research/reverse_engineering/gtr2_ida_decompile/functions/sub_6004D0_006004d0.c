int __userpurge sub_6004D0@<eax>(_DWORD *a1@<ecx>, char a2@<dil>, int a3, int a4, int a5)
{
  if ( (*a1 & 0x100) != 0 )
    return sub_5FFCF0((int)a1, a3, a4, a5, 0);
  else
    return sub_5FFF80((int)a1, a2, a3, a4, a5, 0);
}
