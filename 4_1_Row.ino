
class Row {
  u8 row[3] = { 0, 0, 0 };
  u8 rev[3] = { 0, 0, 0 };
public:
  Row( u8 x[3] );
  Row();
  u8* get();
  u8* getReverse();
};

Row::Row( u8 x[3] ){
  row[0] = x[0];
  row[1] = x[1];
  row[2] = x[2];
  rev[0] = x[2];
  rev[1] = x[1];
  rev[2] = x[0];
};
Row::Row(){};
u8* Row::get(){
  return row;
};
u8* Row::getReverse(){
  return rev;
};
