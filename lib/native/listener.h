#include "orientc_reader.h"
#include <nan.h>
using namespace Orient;

class TrackerListener: public RecordParseListener {
public:
	virtual void startDocument(const char * name,size_t name_length) ;
	virtual void endDocument() ;
	virtual void startField(const char * name,size_t name_length, OType type) ;
	virtual void endField(const char * name,size_t name_length) ;
	virtual void stringValue(const char * value,size_t value_length) ;
	virtual void intValue(long value) ;
	virtual void longValue(long long value) ;
	virtual void shortValue(short value);
	virtual void byteValue(char value) ;
	virtual void booleanValue(bool value);
	virtual void floatValue(float value) ;
	virtual void doubleValue(double value) ;
	virtual void binaryValue(const char * value, int length) ;
	virtual void dateValue(long long value) ;
	virtual void dateTimeValue(long long value) ;
	virtual void linkValue(struct Link &value) ;
	virtual void startCollection(int size);
	virtual void startMap(int size) ;
	virtual void mapKey(const char *key,size_t key_length);
	virtual void endMap();
	virtual void endCollection();

	char * class_name;
	char * field_name;
	OType type;

	v8::Local<v8::Object> obj;
	TrackerListener() ;
	~TrackerListener() ;

};
