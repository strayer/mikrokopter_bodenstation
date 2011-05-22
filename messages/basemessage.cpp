#include "basemessage.h"
#include "boost/crc.hpp"

#include "helper_functions.h"

#include <QtDebug>

BaseMessage::BaseMessage(int type) : _messageType(type)
{
}

int BaseMessage::messageType()
{
	return _messageType;
}

QByteArray BaseMessage::typeIntToBytes()
{
	return QByteArray();
}

QByteArray BaseMessage::encodeForWriting()
{
	QByteArray type = intToQByteArray(messageType(), 3);
	QByteArray data = prepareData();
	QByteArray crc8 = BaseMessage::generateCRC8(QByteArray().append(type).append(data));

	qDebug() << "Type:" << type.toHex();
	qDebug() << "Data:" << data.toHex();
	qDebug() << "CRC8:" << crc8.toHex();

	QByteArray tmp;
	tmp.append(STX);
	tmp.append(STX);
	tmp.append(type);
	tmp.append(data);
	tmp.append(crc8);
	tmp.append(ETB);

	return tmp;
}

QByteArray BaseMessage::escapeByteArray(QByteArray data)
{
	return data;//.replace();
}

QByteArray BaseMessage::generateCRC8(QByteArray data)
{
	boost::crc_basic<8> crc8(0x07);

	crc8.process_bytes(data.constData(), data.length());

	return QByteArray(1, crc8.checksum());
}

QByteArray BaseMessage::prepareData()
{
	return QByteArray();
}