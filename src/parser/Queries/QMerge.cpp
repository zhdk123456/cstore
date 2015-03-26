/* Copyright (c) 2005, Regents of Massachusetts Institute of Technology, 
 * Brandeis University, Brown University, and University of Massachusetts 
 * Boston. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright 
 *     notice, this list of conditions and the following disclaimer in the 
 *     documentation and/or other materials provided with the distribution.
 *   - Neither the name of Massachusetts Institute of Technology, 
 *     Brandeis University, Brown University, or University of 
 *     Massachusetts Boston nor the names of its contributors may be used 
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* QMerge.cpp
 *
 * Created by Tien Hoang on 06/05/2005
 * 
 * Implementation for query: Merge <projection name>
 */

#include "QMerge.h"

QMerge::QMerge() : Query() {
  m_lpProjection = NULL;
}

QMerge::~QMerge()
{

	Log::writeToLog("QMerge", 10, "~QMerge");
}

void QMerge::setProjection(Projection* lpProjection) {
  m_lpProjection = lpProjection;
}

Projection* QMerge::getProjection() {
  return m_lpProjection;
}

string QMerge::toString() {
  string r = "";

  r = "MERGE ";

  Projection* p = getProjection();
  r += p->toString();

  return r;
}

// Generate q query plan
void QMerge::makePlan() {
  /* to uncomment once Nga writes MergePlan.h & .cpp
  
  m_lpPlan = MergePlan::create();
  m_lpPlan->makePlan(this);
  */
}

//---------------------------------------------------------------
// Memory management functions

// New a node and put it in the m_lpList
QMerge* QMerge::create()
{
	Log::writeToLog("QMerge", 0, "Create");
		
	QMerge* lpPObject = new QMerge();
	pushBack(lpPObject);
	return lpPObject;
}
